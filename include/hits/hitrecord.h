#ifndef JUSTINSRAYTRACER_HITRECORD_H
#define JUSTINSRAYTRACER_HITRECORD_H

#include "utility/vec3.h"
#include "utility/ray.h"
#include "hits/materials/material.h"

namespace jrt {
    struct hitdetails {
        hitdetails(ray const& incomingRay, double t, vec3 const& outwardNormal, material const& mat);

        point3 const point;
        double const t;

        bool const hitFront;
        vec3 const normal;

        material const& mat;


        // include material info here as well

    };

    struct hitrecord {
        hitrecord();
        hitrecord(ray const& incoming, double t, vec3 const& outwardNorm, material const& mat);



        bool const didHit;
        std::shared_ptr<hitdetails> const detailsPtr;
    };


}

#endif //JUSTINSRAYTRACER_HITRECORD_H
