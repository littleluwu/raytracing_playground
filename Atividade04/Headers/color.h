#ifndef COLOR_H
#define COLOR_H

#include "../../Atividade02/Headers/vec3.h"
#include "../../Atividade01/Headers/image_utils.h"

#include <iostream>

using color = vec3;

void write_color(RGBv **m, int i, int j, color pixel_color) {
    m[i][j].red = static_cast<int>(255.999 * pixel_color.x());
    m[i][j].green = static_cast<int>(255.999 * pixel_color.y());
    m[i][j].blue = static_cast<int>(255.999 * pixel_color.z());
}

#endif