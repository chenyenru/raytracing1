//
// Created by Chen Yen-Ru on 2023/9/11.
//

#ifndef RAYTRACING1_VEC3_H
#define RAYTRACING1_VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
    public:
        double e[3];
        vec3() : e{0,0,0} {}
        vec3(double e0, double e1, double e2): e{e0, e1, e2} {}

        // configure the behavior for vec3.x, vec3.y, vec3.z
        double x() const {return e[0];}
        double y() const {return e[1];}
        double z() const {return e[2];}

        // configure the behavior for negative sign (-) and vec3[i]
        vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]);}
        double operator[](int i) const {return e[i];}
        double& operator[](int i) const {return e[i];}


        // Vector to Vector operation
        // configure the behavior for -= sign
        vec3& operator-=(const vec3 &v){
            e[0] -= v.e[0];
            e[1] -= v.e[1];
            e[2] -= v.e[2];
        }

        vec3& operator+=(const vec3 &v){
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        // Vector to scalar operations
        // configure *=
        vec3& operator*=(double t){
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;

            return *this;
        }

        // configure /=
        vec3& operator/=(double t){
            return *this *= (1/t);
        }

        double length() const{
            return sqrt(length_squared());
        }

        double length_squared() const{
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
};

#endif //RAYTRACING1_VEC3_H
