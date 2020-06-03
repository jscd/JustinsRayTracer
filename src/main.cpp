#include <iostream>
#include <fstream>

#include "renderer.h"
#include "hits/objects/sphere.h"

#include "hits/materials/lambertian.h"
#include "hits/materials/metal.h"
#include "hits/materials/fuzzedmetal.h"
#include "hits/materials/dielectric.h"


#include "utility/debug.h"

int main() {
    constexpr double aspectRatio = 16.0/9.0;
    constexpr int screenWidth = 1080;
    constexpr double viewportHeight = 2.0;

    constexpr int samples = 25;

    jrt::dimensions<int> screenDimensions(aspectRatio);
    screenDimensions.setWidth(screenWidth);

    std::cout << "Dimensions: " << screenDimensions << std::endl;

    jrt::dimensions<double> viewportDimensions(aspectRatio);
    viewportDimensions.setHeight(viewportHeight);

    // Create world
    jrt::world wrld(20);


    jrt::lambertian s1material(jrt::color(0.7, 0.3, 0.3));
    jrt::sphere<jrt::lambertian> s1(0.5, jrt::point3(0, 0, -2), s1material);
    wrld->push_back(s1);

    jrt::metal s2material(jrt::color(0.3, 0.3, 0.7));
    jrt::sphere<jrt::metal> s2(0.5, jrt::point3(-1, 0.0, -1.05), s2material);
    wrld->push_back(s2);

    jrt::lambertian s3material(jrt::color(0.3, 0.7, 0.3));
    jrt::sphere<jrt::lambertian> s3(100, jrt::point3(0, -100.5, -1), s3material);
    wrld->push_back(s3);

    jrt::fuzzedmetal s4material(jrt::color(0.7, 0.7, 0.3), 0.4);
    jrt::sphere<jrt::fuzzedmetal> s4(0.5, jrt::point3(1, 0.0, -0.95), s4material);
    wrld->push_back(s4);

    jrt::dielectric s5material(jrt::color(1, 1, 1), 1.5);
    jrt::sphere<jrt::dielectric> s5(-0.5, jrt::point3(0.0, 0.0, -1), s5material);
    wrld->push_back(s5);

    // Initialize camera
    jrt::camera camera(viewportDimensions, jrt::point3(0,1,1), jrt::point3(0, 0, 0), 1.0, wrld);


    // Initialize renderer
    jrt::renderer renderer(screenDimensions, camera, samples);



    // Render to file!
    std::ofstream outputFile("test.ppm");
    renderer.render(outputFile);
    outputFile.close();

    return 0;
}
