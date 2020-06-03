#ifndef JUSTINSRAYTRACER_UTILITY_H
#define JUSTINSRAYTRACER_UTILITY_H

#include <limits>
#include <random>

namespace jrt {

    constexpr double pi = 3.14159265358979;
    constexpr double infinity = std::numeric_limits<double>::infinity();


    template<typename T>
    constexpr T lerp(T const& start, T const& end, double t) {
        return (1 - t)*start + t*end;
    }

    double random();

    double random(double min, double max);

}

#endif //JUSTINSRAYTRACER_UTILITY_H
