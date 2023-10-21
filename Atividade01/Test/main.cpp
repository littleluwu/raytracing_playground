#include <iostream>
#include "../Headers/image_utils.h"

using namespace std;

int main(){
    //First Image
    //Black to Red Gradient
    char *path = "./gradient.png";
    RGBv **m = (RGBv **)malloc(256*sizeof(RGBv *));
    for (int i = 0; i < 256; i++) m[i] = (RGBv *)malloc(256*sizeof(RGBv));

    for (int i = 0; i < 256; i++){
        for (int j = 0; j < 256; j++){
            m[i][j].red = j;
            m[i][j].green = 0;
            m[i][j].blue = 0;
        }
    }
    save_image(path,m,256,256);

    //Second Image
    //Pink square on a White canvas
    int square = 100;
    int center = 256/2;
    path = "./square.png";
    for (int i = 0; i < 256; i++){
        for (int j = 0; j < 256; j++){
            if (i > center-square/2 && i < center+square/2 && j > center-square/2 && j < center+square/2){
                m[i][j].red = 255;
                m[i][j].green = 0;
                m[i][j].blue = 255;
            }
            else {
                m[i][j].red = 255;
                m[i][j].green = 255;
                m[i][j].blue = 255;
            }
        }
    }
    save_image(path,m,256,256);

    //Third Image
    //Red circle on a Black canvas
    int radius = 75;
    center = 256/2;
    path = "./circle.png";
    for (int i = 0; i < 256; i++){
        for (int j = 0; j < 256; j++){
            if ((i-center)*(i-center) + (j-center)*(j-center) <= radius*radius){
                m[i][j].red = 255;
                m[i][j].green = 0;
                m[i][j].blue = 0;
            }
            else {
                m[i][j].red = 20;
                m[i][j].green = 20;
                m[i][j].blue = 20;
            }
        }
    }

    save_image(path,m,256,256);

    for (int i = 0; i < 256; i++) free(m[i]);
    free(m);

    return 0;
}