#ifndef JUSTINSRAYTRACER_RAY_H
#define JUSTINSRAYTRACER_RAY_H

#include "vec3.h"

namespace jrt {
class ray {
public:
    ray(point3 const& origin, vec3 const& direction);

    point3 const origin;
    vec3 const direction;

    [[nodiscard]] point3 at(double t) const;
};
}

#endif //JUSTINSRAYTRACER_RAY_H
