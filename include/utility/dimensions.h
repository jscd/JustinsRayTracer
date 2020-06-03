#ifndef JUSTINSRAYTRACER_DIMENSIONS_H
#define JUSTINSRAYTRACER_DIMENSIONS_H

#include <ostream>

namespace jrt{
template<typename T>
class dimensions {
public:
    /// aspectRatio Should be width/height
    explicit dimensions(double aspectRatio) : aspectRatio(aspectRatio) { }

    inline T getWidth()  const { return width; }
    inline T getHeight() const { return height; }

    void setWidth(T const& width) {
        this->width = width;
        height = static_cast<T>(width / aspectRatio);
    }

    void setHeight(T const& height) {
        this->height = height;
        width = static_cast<T>(height * aspectRatio);
    }

    double const aspectRatio;

private:
    T width;
    T height;
};

template<typename T>
std::ostream& operator<<(std::ostream& o, dimensions<T> dim) {
    return o << std::to_string(dim.getWidth()) << 'x' << std::to_string(dim.getHeight());
}

}

#endif //JUSTINSRAYTRACER_DIMENSIONS_H
