# :pencil2:- Atividade01 - Image I/O

For this assignment, I wrote a function to manage saving images on the disk. We chose primarily PNG encoding when dealing with images, thus using the `libpng` library. To test the save function, We represented some images in a 2D array of 256x256 and used the function `save_image()` to save them into .png files.

## :page_facing_up: Functions Description

### :pushpin: Save Image

**`save_image(char *path, RGBv **m, int height, int width)`**

`path` - File path on which the image will be stored. Includes the name of the image.Ex: "./images/image01.png"

`m` - 2d array of pixels that represents the image to be saved. The type of the array needs to be RGBv, where each element holds the three color values of a pixel.

`height` - Height in pixels of the image.

`width` - Width in pixels of the image.

The save function utilizes the classes and types provided by libpng. With the given image, represented as a 2D array, we add each pixel in a row to a row pointer called `row`. At the end of each row, I store the information in the `png_pntr`, which holds the whole data for the image. After passing through each row, the image file is encoded using the information from `pnt_pntr` and saved into the disk.

The function returns a flag for eventual errors. Return code 1 means that an error occurred during the process. Return code 0 indicates that everything was done successfully.

## :test_tube: Unit Tests


In total, I generated three images just for testing purposes:

- A red to black gradient.

![Red to Black gradient](/Atividade01/Test/output/gradient.png)

- A red circle in a black canvas.

![Red circle in a black canvas](/Atividade01/Test/output/circle.png)

- A pink square in a white canvas.

![Pink square in a white canvas](/Atividade01/Test/output/square.png)

> A load function is yet to be written for use on future assignments.