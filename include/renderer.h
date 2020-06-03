#ifndef JUSTINSRAYTRACER_RENDERER_H
#define JUSTINSRAYTRACER_RENDERER_H

#include <iostream>
#include <map>

#include "utility/dimensions.h"
#include "utility/vec3.h"
#include "camera.h"

namespace jrt {
    class renderer {
    public:
        renderer(dimensions<int> const& screen, camera const& cam, unsigned int samples);

        /// Outputs to PPM
        void render(std::ostream& output);

        dimensions<int> const screen;
        unsigned int const samples;


    private:
        inline void writeColor(color const& color, std::ostream& o) const;

        jrt::camera cam;
    };
}


#endif //JUSTINSRAYTRACER_RENDERER_H
