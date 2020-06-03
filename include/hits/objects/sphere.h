#ifndef JUSTINSRAYTRACER_SPHERE_H
#define JUSTINSRAYTRACER_SPHERE_H

#include "hits/hittable.h"
#include "hits/materials/material.h"

#include "utility/vec3.h"

namespace jrt {

    template<typename T>
    class sphere : public hittable, public hasMaterial<T> {
    public:
        sphere(double radius, point3 const& c, T const& mat);

        virtual hitrecord hit(ray const &r, double tMin, double tMax) const override;

        double const radius;
        point3 const center;
    };
}

#endif //JUSTINSRAYTRACER_SPHERE_H
