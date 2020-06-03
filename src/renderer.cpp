#include "renderer.h"
#include "utility/debug.h"

#include "utility/vec3.h"
#include "utility/utility.h"

using namespace jrt;

renderer::renderer(dimensions<int> const& scrDim, camera const& c, unsigned int sampling) : screen(scrDim), cam(c), samples(sampling) { }


void renderer::render(std::ostream &output) {
    debug << "Starting render..." << std::endl;

    // PPM heading
    output << "P3\n";
    output << screen.getWidth() << ' ' << screen.getHeight() << '\n';
    output << "255\n";

    for(int y = screen.getHeight() - 1; y >= 0; --y){
        // Very extra progress indicator
        debug << "\rProgress:\t"
              << std::to_string((screen.getHeight() - double(y))/(screen.getHeight() - 1)*100.0).substr(0, 5)
              << "%    " << std::flush;
        for(int x = 0; x < screen.getWidth(); ++x){
            color netColor = color(0);

            for(int s = 0; s < samples; s++){
                double const xfrac = (x + jrt::random()) / (screen.getWidth() - 1);
                double const yfrac = (y + jrt::random()) / (screen.getHeight() - 1);

                netColor += cam.get(xfrac, yfrac);
            }

            auto sampled = netColor/samples;
            auto gammaCorrected = color(sqrt(sampled.x()), sqrt(sampled.y()), sqrt(sampled.z()));

            this->writeColor(gammaCorrected, output);
        }
    }
    debug << "\nDone." << std::endl;
}

inline void renderer::writeColor(color const& c, std::ostream &o) const {
    o << static_cast<int>(255.999 * c.x()) << ' '
      << static_cast<int>(255.999 * c.y()) << ' '
      << static_cast<int>(255.999 * c.z()) << '\n';
}
