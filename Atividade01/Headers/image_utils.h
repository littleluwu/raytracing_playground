#ifndef image_utils
#define image_utils

#include <iostream>

using namespace std;

typedef struct {
    int red;
    int green;
    int blue;
} RGBv;

int save_image(char *path, RGBv **m, int height, int width);

int load_image(char *path, RGBv **m, int height, int width);

#endif