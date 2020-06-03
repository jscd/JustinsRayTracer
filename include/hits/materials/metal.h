#ifndef JUSTINSRAYTRACER_METAL_H
#define JUSTINSRAYTRACER_METAL_H

#include "material.h"
#include "utility/ray.h"
#include "hits/hitrecord.h"

namespace jrt {
    class metal : public material {
    public:
        metal(color const& albedo);

        virtual ray scatter(ray const& inRay, hitrecord const& record, color *attenuation) const override;
        color const albedo;

    protected:
        vec3 reflect(vec3 const& v, vec3 const& n) const;
    };
}

#endif //JUSTINSRAYTRACER_METAL_H
