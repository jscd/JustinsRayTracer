#ifndef JUSTINSRAYTRACER_LAMBERTIAN_H
#define JUSTINSRAYTRACER_LAMBERTIAN_H

#include "material.h"
#include "utility/ray.h"
#include "hits/hitrecord.h"

namespace jrt {
    class lambertian : public material {
    public:
        lambertian(color const& albedo);

        virtual ray scatter(ray const& inRay, hitrecord const& record, color *attenuation) const override;
        color const albedo;
    };
}

#endif //JUSTINSRAYTRACER_LAMBERTIAN_H
