#ifndef JUSTINSRAYTRACER_DIELECTRIC_H
#define JUSTINSRAYTRACER_DIELECTRIC_H

#include "material.h"
#include "utility/ray.h"
#include "hits/hitrecord.h"
#include "metal.h"

namespace jrt {
    class dielectric : public metal {
    public:
        dielectric(color const& tint, double refractiveRatio);

        virtual ray scatter(ray const& inRay, hitrecord const& record, color *attenuation) const override;

        double const refractiveRatio;

    private:
        vec3 refract(vec3 const& uv, vec3 const& n, double refr) const;
        double schlick(double cosine, double ref_idx) const;

    };
}

#endif //JUSTINSRAYTRACER_DIELECTRIC_H
