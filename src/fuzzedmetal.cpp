#include "hits/materials/fuzzedmetal.h"

#include "utility/vecrand.h"

using namespace jrt;

fuzzedmetal::fuzzedmetal(const color &albedo, double fuzz) : metal(albedo), fuzziness(fuzz < 1 ? fuzz : 1) {}

ray fuzzedmetal::scatter(const ray &inRay, const hitrecord &record, color *attenuation) const {
    *attenuation = albedo;

    vec3 reflectDirect = metal::reflect(inRay.direction.normalize(), record.detailsPtr->normal);

    ray scattered(record.detailsPtr->point, reflectDirect + fuzziness * vec3rand::unitvector());

    if(dot(scattered.direction, record.detailsPtr->normal) > 0) return scattered;
    return ray(point3(0), vec3(0));
}