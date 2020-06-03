#include "hits/hitrecord.h"

using namespace jrt;

hitrecord::hitrecord() : didHit(false) { }

hitrecord::hitrecord(const ray &incoming, double t, const vec3 &outwardNorm, material const& m)
    : didHit(true), detailsPtr(std::make_shared<hitdetails>(incoming, t, outwardNorm, m)) {  }


hitdetails::hitdetails(const ray &r, double t, const vec3 &outwardNormal, material const& m)
    : t(t), point(r.at(t)), hitFront(dot(r.direction, outwardNormal) < 0),
      normal(hitFront ? (outwardNormal) : (-outwardNormal)),
      mat(m) { }