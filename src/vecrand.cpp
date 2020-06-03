//
// Created by Justin DeSimpliciis on 5/29/20.
//

#include "utility/vecrand.h"

#include "utility/vec3.h"

using namespace jrt;


vec3 vec3rand::unitvector() {
    auto radians = jrt::random(0, 2*jrt::pi);
    auto z = jrt::random(0, -1);
    auto r = std::sqrt(1 - z*z);

    return vec3(r*cos(radians), r*sin(radians), z);
}

vec3 vec3rand::vector() {
    return vec3(jrt::random(), jrt::random(), jrt::random());
}

vec3 vec3rand::vector(double min, double max) {
    return vec3(jrt::random(min, max), jrt::random(min, max), jrt::random(min, max));
}

vec3 vec3rand::withinunitsphere() {
    while (true) {
        auto p = vec3rand::vector(-1,1);
        if (p.squareLength() >= 1) continue;
        return p;
    }
}
