//
// Created by Chen Yen-Ru on 2023/9/11.
//

#include "vec3.h"

#ifndef RAYTRACING1_RAY_H
#define RAYTRACING1_RAY_H
class ray {
    public:
        ray() {}

        /**
         * This ray constructor takes in point3 as origin. a vec3 as direction.
         * @param origin point3. position vector. used to initialize private var "orig"
         * @param direction vec3. direction vector. used to initialize private var "dir"
         * @return
         */
        ray(const point3& origin, const vec3& direction): orig(origin), dir(direction) {}

        point3 origin() const {return orig;}
        vec3 direction() const {return dir;}

        point3 at(double t) const {
            return orig + t*dir;
        }

    private:
        point3 orig;
        vec3 dir;
};
#endif //RAYTRACING1_RAY_H
