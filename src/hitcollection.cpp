#include "hits/hitcollection.h"

using namespace jrt;

hitrecord hitcollection::hit(const ray &r, double tMin, double tMax) const {
    double closest = tMax;
    bool everHit = false;
    std::shared_ptr<hitrecord> record;

    for(auto const& item : _list){
        hitrecord hit = item.get().hit(r, tMin, closest);
        if(hit.didHit){
            record = std::make_shared<hitrecord>(hit);
            closest = hit.detailsPtr->t;
            everHit = true;
        }
    }

    if(!everHit) return hitrecord();
    return *record;
}

std::vector<std::reference_wrapper<hittable>>* hitcollection::operator->() {
    return &_list;
}

hitcollection::hitcollection() { }
