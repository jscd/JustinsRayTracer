#include "hits/materials/lambertian.h"

#include "utility/vecrand.h"

using namespace jrt;

lambertian::lambertian(const color &a) : albedo(a) {}


ray lambertian::scatter(const ray &inRay, const hitrecord &record, color *attenuation) const {
    *attenuation = albedo;
    return ray(record.detailsPtr->point, record.detailsPtr->normal + jrt::vec3rand::unitvector());
}