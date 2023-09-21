//
// Created by Chen Yen-Ru on 2023/9/15.
//

#ifndef RAYTRACING1_HITTABLE_H
#define RAYTRACING1_HITTABLE_H

#include "rtweekend.h"

class material;

class hit_record {
    public:
        point3 p;
        vec3 normal;
        shared_ptr<material> mat;
        double t;
        // remembering the side of the surface
        bool front_face;

        void set_face_normal(const ray& r, const vec3& outward_normal) {
            // Sets the hit record normal vector
            // NOTE: the parameter "outward_normal" is assumed to have unit length.

            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        }
};

class hittable {
    public:
        virtual ~hittable() = default;

        // the const=0 enforced derived class implementation
        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif //RAYTRACING1_HITTABLE_H
