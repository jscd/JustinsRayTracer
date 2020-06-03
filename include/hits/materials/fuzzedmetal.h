#ifndef JUSTINSRAYTRACER_FUZZEDMETAL_H
#define JUSTINSRAYTRACER_FUZZEDMETAL_H

#include "metal.h"

namespace jrt {
    class fuzzedmetal : public metal {
    public:
        fuzzedmetal(color const &albedo, double fuzziness);

        virtual ray scatter(const ray &inRay, const hitrecord &record, color *attenuation) const override;

        double const fuzziness;
    };
}

#endif //JUSTINSRAYTRACER_FUZZEDMETAL_H
