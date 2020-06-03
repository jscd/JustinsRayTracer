#ifndef JUSTINSRAYTRACER_HITCOLLECTION_H
#define JUSTINSRAYTRACER_HITCOLLECTION_H

#include <vector>
#include "hittable.h"

namespace jrt {
class hitcollection : public hittable {
public:
    hitcollection();

    virtual hitrecord hit(ray const &r, double tMin, double tMax) const override;

    std::vector<std::reference_wrapper<hittable>>* operator->();

private:
    std::vector<std::reference_wrapper<hittable>> _list;
};
}

#endif //JUSTINSRAYTRACER_HITCOLLECTION_H
