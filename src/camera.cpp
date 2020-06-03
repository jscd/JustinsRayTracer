#include "camera.h"

using namespace jrt;

camera::camera(const dimensions<double> &vp, const point3 &o, const point3 &at, double fd, world& w)
    : viewport(vp), origin(o), focalDistance(fd), wrld(w),
      lookDir((o - at).normalize()),
      horizontal(vp.getWidth() * cross(vec3(0, 1, 0), lookDir)),
      vertical(vp.getHeight() * cross(lookDir, horizontal/vp.getWidth())),
      lowerLeft(origin - 0.5*horizontal - 0.5*vertical - lookDir - vec3(0, 0, fd)) { }

ray camera::getRay(double xfraction, double yfraction) const {
    static const auto constCalculatedDirComponent = lowerLeft - origin;
    return ray(origin, constCalculatedDirComponent + xfraction*horizontal + yfraction*vertical);
}


world &camera::getWorld() {
    return wrld;
}

color camera::get(double xfrac, double yfrac) {
    return wrld.getHit(this->getRay(xfrac, yfrac));
}
