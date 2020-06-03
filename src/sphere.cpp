#include "hits/objects/sphere.h"

#include <cmath>

#include "hits/materials/lambertian.h"
#include "hits/materials/metal.h"
#include "hits/materials/fuzzedmetal.h"
#include "hits/materials/dielectric.h"

using namespace jrt;

template<typename T>
sphere<T>::sphere(double r, const point3 &c, T const& mat) : radius(r), center(c), hasMaterial<T>(mat) { }

template<typename T>
hitrecord sphere<T>::hit(const ray &r, double tMin, double tMax) const {
    vec3 otoc = r.origin - center;

    auto const a = r.direction.squareLength();
    auto const halfb = dot(r.direction, otoc);
    auto const c = otoc.squareLength() - (radius * radius);

    auto const discriminant = halfb * halfb - a * c;

    if(discriminant >= 0){
        auto const root = std::sqrt(discriminant);
        double const zeros[2] = { (-halfb - root)/a ,
                            (-halfb + root)/a };

        for(double const zero : zeros){
            if(zero >= tMin && zero <= tMax){
                auto hitpoint = r.at(zero);
                return hitrecord(r, zero, (hitpoint - center) / radius, this->mat);
            }
        }
    }

    return hitrecord();

}

template class jrt::sphere<lambertian>;
template class jrt::sphere<metal>;
template class jrt::sphere<fuzzedmetal>;
template class jrt::sphere<dielectric>;