//
// Created by Chen Yen-Ru on 2023/9/16.
//

#ifndef RAYTRACING1_INTERVAL_H
#define RAYTRACING1_INTERVAL_H

class interval {
    public:
        double min, max;

        interval() : min(+infinity), max(-infinity) {} // Default interval is empty

        interval(double _min, double _max) : min(_min), max(_max) {}

        bool contains(double x) const {
            return min <= x && x <= max;
        }

        bool surrounds(double x) const {
            return min < x && x < max;
        }

        /**
         * Ensures that the color components remain within the [0,1] range
         * @param x
         * @return
         */
        double clamp(double x) const{
            if(x<min) return min;
            if(x>max) return max;
            return x;
        }

        static const interval empty, universe;
};

const static interval empty(+infinity, -infinity);
const static interval universe(-infinity, +infinity);

#endif //RAYTRACING1_INTERVAL_H
