# :books:  Learning the basics Raytracing 

This repository is an attempt to learn the concepts and fundamentals of raytracing. The code presented here follows the assignments from the class `1001315 - COMPUTAÇÃO GRÁFICA`, lectured by the professor __Mario A. S. Lizier__ on the __Universidade Federal de Sao Carlos - Campus Sorocaba__. The class structure bases itself on the series of books __Raytracing in One Weekend__, written by Peter Shirley, Trevor David Black, and Steve Hollasch. 

## :card_index_dividers:- How it is organized 

I divided this repository into sections where each section corresponds to one assignment. These divisions follow the labeling pattern `AtividadeXX` in which the __XX__ corresponds to the assignment number.

Additionally, I also dissect the subsections with the objective of further organizing the files in this repository. They present a structure like the following:

- **Headers** - A folder containing the header file declarations used in the assignment.
- **Sources** - A folder with the headers implementations and source files utilized.
- **Test** - A folder for the testing files to ensure the projected functions and classes work as wanted.

## :hammer:- Dependencies

- libpng

# :memo: Atividades

In a short text format, I describe the work done and project decisions made. For each assignment, there is a corresponding subsection with such descriptions.

## :pencil2:- Atividade01 - Image I/O

For this assignment, I wrote a function to manage saving images on the disk. I chose primarily PNG encoding when dealing with images, thus using the `libpng` library. To test the save function, I represented some images in a 2D array of 256x256 and used the function `save_image()` to save them into .png files. 

> A load function is yet to be written for use on future assignments.

## :pencil2:- Atividade02 - Matrix Operations

This assignment set some groundwork for the rest of the project. For convenience when dealing with vectors and matrices later, I created two vector classes (`vec3` and `vec4`) and three matrix classes (`mat2`, `mat3`, and `mat4`) along with their operations. I started experimenting with unit tests for testing the classes. For the time being, I only experimented sufficiently with the vector classes. 

> Unit tests for matrix classes pending.
