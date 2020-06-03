#ifndef JUSTINSRAYTRACER_WORLD_H
#define JUSTINSRAYTRACER_WORLD_H

#include "hitcollection.h"

namespace jrt {
class world {
public:
    explicit world(unsigned int maxDepth);

    hitcollection& operator->();

    color getHit(ray const& incomingRay) const;

private:
    hitcollection collection;
    unsigned int const maxDepth;

    color getHit(ray const& incomingRay, int depth) const;

    color getBackground(ray const& incomingRay) const;
};
}

#endif //JUSTINSRAYTRACER_WORLD_H
