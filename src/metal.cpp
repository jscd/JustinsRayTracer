#include "hits/materials/metal.h"


using namespace jrt;

metal::metal(const color &a) : albedo(a) { }

ray metal::scatter(const ray &inRay, const hitrecord &record, color *attenuation) const {
    *attenuation = albedo;

    vec3 const reflectDirect = reflect(inRay.direction.normalize(), record.detailsPtr->normal);

    ray scattered(record.detailsPtr->point, reflectDirect);

    if(dot(scattered.direction, record.detailsPtr->normal) > 0) return scattered;
    return ray(point3(0), vec3(0));
}

vec3 metal::reflect(const vec3 &v, const vec3 &n) const {
    return v - 2 * dot(v, n) * n;
}
