//
// Created by Chen Yen-Ru on 2023/9/11.
// Writes a single color out to the standard output stream
//

#ifndef RAYTRACING1_COLOR_H
#define RAYTRACING1_COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

void write_color(std::ostream &out, color pixel_color){
    // Write the translated [0, 255] value of each color component
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
    << static_cast<int>(255.999 * pixel_color.y()) << ' '
    << static_cast<int>(255.999 * pixel_color.z()) << "\n";
}

#endif //RAYTRACING1_COLOR_H
