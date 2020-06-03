cmake_minimum_required(VERSION 3.16)
project(JustinsRayTracer)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
set(SOURCES src/main.cpp src/renderer.cpp src/ray.cpp src/vec3.cpp
            src/camera.cpp src/hitrecord.cpp src/hitcollection.cpp
            src/world.cpp src/sphere.cpp src/lambertian.cpp
            src/vecrand.cpp src/utility.cpp src/metal.cpp src/fuzzedmetal.cpp src/dielectric.cpp)

add_executable(JustinsRayTracer ${SOURCES})