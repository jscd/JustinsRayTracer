#ifndef JUSTINSRAYTRACER_MATERIAL_H
#define JUSTINSRAYTRACER_MATERIAL_H

#include "utility/ray.h"

namespace jrt {
    struct hitrecord;


    class material {
    public:
        virtual ray scatter(ray const& inRay, hitrecord const& record, color *attenuation) const = 0;
    };


    template<typename DerivedMaterial>
    class hasMaterial {
    public:
        hasMaterial(DerivedMaterial const& m) : mat(m) {
            static_assert(std::is_base_of<jrt::material, DerivedMaterial>::value, "Derived material must be a child of material!");
        }

        DerivedMaterial const mat;
    };
}

#endif //JUSTINSRAYTRACER_MATERIAL_H
