#ifndef image_utils
#define image_utils

#include <iostream>
#include <math.h>
#include <malloc.h>
#include <png.h> //Need libpng

using namespace std;

typedef struct {
    int red;
    int green;
    int blue;
} RGBv;


/**
 * @brief Saves a 2D array in a image file.
 * 
 * This function takes a 2D array that represents an image, where each element holds the three color
 * values for an RGB image, and saves them into a PNG file using the library libpng. The height and width
 * of the image needs to be passed to generate the .png file, as well as a path where the file will be
 * store. It is important that the path string contains the image name, not just the folder where you
 * want to save the image.
 * 
 * @param path File path on which the image will be stored. Includes the name of the image.
 *             Ex: "./images/image01.png"
 * @param m 2d array of pixels that represents the image to be saved. The type of the array needs to be
 *          RGBv, where each element holds the three color values of a pixel.
 * @param height Height in pixels of the image
 * @param width Width in pixels of the image
 * @return The function returns a flag for eventual errors. Return code 1 means that an
 *         error occurred during the process. Return code 0 indicates that everything was done successfully.
 */
int save_image(char *path, RGBv **m, int height, int width){
    int code = 1; //Return code
    FILE *fp = fopen(path,"wb");
    if (!fp) return code;

    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
        fclose(fp);
        return code;
    }

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr){
        fclose(fp);
        free(png_ptr);
        return code;
    }

    png_bytep row = NULL;   
    setjmp(png_jmpbuf(png_ptr));
    png_init_io(png_ptr, fp);
    png_set_IHDR(
        png_ptr, 
        info_ptr, 
        width, 
        height,
        8, //Stardard depth of 8bits
        PNG_COLOR_TYPE_RGB, 
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_BASE, 
        PNG_FILTER_TYPE_BASE
        );
    
    png_text title_text;
    title_text.compression = PNG_TEXT_COMPRESSION_NONE;
    title_text.key = "title";
    title_text.text = "sample";

    png_set_text(png_ptr, info_ptr, &title_text, 1);
    png_write_info(png_ptr, info_ptr);

    row = (png_bytep) malloc(sizeof(png_byte)*width*3);
    for(int y=0; y < height; y++) {
        for(int x=0; x < width; x++) {
            row[x*3] = m[x][y].red;
            row[x*3+1] = m[x][y].green;
            row[x*3+2] = m[x][y].blue;
        }
        png_write_row(png_ptr, row);
    }
    png_write_end(png_ptr, info_ptr);

    //"Freeing" the pointers.
    fclose(fp);
    free(png_ptr);
    free(info_ptr);

    code = 0; //Saved successfully.
    return code;      
}

int load_image(char *path, RGBv **m, int height, int width){
    int code = 1; //Return code
    return code;
}

#endif