//
// Created by Chen Yen-Ru on 2023/9/15.
//

#ifndef RAYTRACING1_SPHERE_H
#define RAYTRACING1_SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
    public:
        sphere(point3 _center, double _radius) : center(_center), radius(_radius) {}

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            vec3 oc = r.origin() - center;
            auto a = dot(r.direction(), r.direction());
            auto half_b = 2.0 * dot(r.direction(), oc);
            auto c = dot(oc, oc) - radius * radius;

            auto discriminant = half_b * half_b - 4 * a * c;
            if (discriminant < 0) return false;
            auto sqrtd = sqrt(discriminant);

            // Find the nearest root that lies in the acceptable range
            auto root = (-half_b - sqrtd) / a;
            if (!ray_t.surrounds(root)) {
                root = (-half_b + sqrtd) / a;
                if (!ray_t.surrounds(root))
                    return false;
            }

            rec.t = root;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);

            return true;
        }

    private:
        point3 center;
        double radius;
};

#endif //RAYTRACING1_SPHERE_H
