#include "hits/materials/dielectric.h"

#include <cmath>

#include "utility/utility.h"

using namespace jrt;

dielectric::dielectric(color const& t, double r) : metal(t), refractiveRatio(r) { }

ray dielectric::scatter(const ray &inRay, const hitrecord &record, color *attenuation) const {
    *attenuation = albedo;  // Tint

    double const usedRefIdx = (record.detailsPtr->hitFront) ? 1.0/refractiveRatio : refractiveRatio;

    vec3 const& unitDir = inRay.direction.normalize();

    double const cosTheta = fmin(dot(-unitDir, record.detailsPtr->normal), 1.0);
    double const sinTheta = std::sqrt(1.0 - cosTheta*cosTheta);


    if(usedRefIdx * sinTheta > 1.0 || (jrt::random() < this->schlick(cosTheta, usedRefIdx))){ // MUST reflect
        return ray(record.detailsPtr->point, reflect(unitDir, record.detailsPtr->normal));
    }


    return ray(record.detailsPtr->point, this->refract(unitDir, record.detailsPtr->normal, usedRefIdx));
}

vec3 dielectric::refract(const vec3 &uv, const vec3 &n, double refr) const {
    auto const cosTheta = dot(-uv, n);
    vec3 const parallel = refr * (uv + cosTheta*n);
    vec3 const perp = -std::sqrt(1.0 - parallel.squareLength()) * n;

    return parallel + perp;
}

double dielectric::schlick(double cosine, double ref_idx) const {
    auto r0 = (1-ref_idx) / (1+ref_idx);
    r0 = r0*r0;
    return r0 + (1-r0)*pow((1 - cosine),5);
}
