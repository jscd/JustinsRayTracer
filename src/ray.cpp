#include "utility/ray.h"

#include "utility/vec3.h"

using namespace jrt;

ray::ray(point3 const& o, vec3 const& dir) : origin(o), direction(dir) { }

point3 ray::at(double t) const {
    return origin + direction * t;
}