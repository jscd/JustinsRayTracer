#include <random>

#include "utility/utility.h"

double jrt::random() {
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_real_distribution<double> distrib(0.0, 1.0);

    return distrib(generator);
}

double jrt::random(double min, double max) {
    return min + (max - min) * random();
}