#ifndef JUSTINSRAYTRACER_HITTABLE_H
#define JUSTINSRAYTRACER_HITTABLE_H

#include "hitrecord.h"

namespace jrt {
    class hittable {
    public:
        virtual hitrecord hit(ray const &r, double tMin, double tMax) const = 0;

//        bool operator<(hittable const &h) const;

    };
}

#endif //JUSTINSRAYTRACER_HITTABLE_H
