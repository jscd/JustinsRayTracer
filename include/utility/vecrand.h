#ifndef JUSTINSRAYTRACER_VECRAND_H
#define JUSTINSRAYTRACER_VECRAND_H

#include "vec3.h"
#include "utility/utility.h"

namespace jrt {
    namespace vec3rand {
        vec3 unitvector();

        vec3 vector();

        vec3 vector(double min, double max);

        vec3 withinunitsphere();
    }
}

#endif //JUSTINSRAYTRACER_VECRAND_H
