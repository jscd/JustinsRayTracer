#include "hits/world.h"

#include "utility/utility.h"
#include "hits/materials/material.h"

using namespace jrt;


world::world(unsigned int md) : maxDepth(md) { }

color world::getHit(const ray &incomingRay) const {
    return this->getHit(incomingRay, 0);
}

hitcollection& world::operator->() {
    return collection;
}

color world::getBackground(ray const& r) const {
    static const color end(0.3, 0.3, 0.7);
    static const color start(1.0, 1.0, 1.0);

    return lerp(start, end, 0.5*(r.direction.normalize().y() + 1.0));
}

color world::getHit(const ray &incomingRay, int depth) const {
    if(depth >= maxDepth) return color(0);

    hitrecord record = collection.hit(incomingRay, 0.01, infinity);
    if(record.didHit){
        color pixcolor(0);
        ray result = record.detailsPtr->mat.scatter(incomingRay, record, &pixcolor);
        static const auto zeroDir = vec3(0);
        if(result.direction == zeroDir) return color(0);
        return (pixcolor * getHit(result, depth + 1));
    } else {
        return getBackground(incomingRay);
    }
}
