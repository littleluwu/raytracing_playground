# :pencil2:- Atividade01 - Image I/O

For this assignment, I wrote a function to manage saving images on the disk. I chose primarily PNG encoding when dealing with images, thus using the `libpng` library. To test the save function, I represented some images in a 2D array of 256x256 and used the function `save_image()` to save them into .png files.

The save function utilizes the classes and types provided by `libpng`. With the given image, represented as a 2D array, we add each pixel in a row to a row pointer called `row`. At the end of each row, I store the information in the `png_pntr`, which holds the whole data for the image. After passing through each row, the image file is encoded using the information from `pnt_pntr` and saved into the disk.

In total, I generated three images just for testing purposes:

- A red to black gradient.

![Red to Black gradient](/Atividade01/Test/gradient.png)

- A red circle in a black canvas.

![Red circle in a black canvas](/Atividade01/Test/circle.png)

- A pink square in a white canvas.

![Pink square in a white canvas](/Atividade01/Test/square.png)

> A load function is yet to be written for use on future assignments.