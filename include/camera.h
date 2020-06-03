#ifndef JUSTINSRAYTRACER_CAMERA_H
#define JUSTINSRAYTRACER_CAMERA_H

#include "utility/dimensions.h"

#include "utility/vec3.h"
#include "utility/ray.h"

#include "hits/world.h"

namespace jrt {
class camera {
public:
    camera(dimensions<double> const& viewport, point3 const& origin, point3 const& pointAt, double focalDistance, world& wrld);

    dimensions<double> const viewport;
    point3 const origin;
    double const focalDistance;

    [[nodiscard]] ray getRay(double xfraction, double yfraction) const;

    color get(double xfrac, double yfrac);


    world& getWorld();

private:
    vec3 const horizontal;
    vec3 const vertical;
    vec3 const lowerLeft;

    vec3 const lookDir;

    jrt::world& wrld;
};
}

#endif //JUSTINSRAYTRACER_CAMERA_H
