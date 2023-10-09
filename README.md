# Learning the basics Raytracing

This repository is an attempt to learn the concepts and fundamentals of raytracing. The code presented here follows the assignments from the class `1001315 - COMPUTAÇÃO GRÁFICA`, lectured by the professor __Mario A. S. Lizier__ on the __Universidade Federal de Sao Carlos - Campus Sorocaba__. The class structure bases itself on the series of books __Raytracing in One Weekend__, written by Peter Shirley, Trevor David Black, and Steve Hollasch. 

## How it is organized

I divided this repository into sections where each section corresponds to one assignment. These divisions follow the labeling pattern `AtividadeXX` in which the __XX__ corresponds to the assignment number.

## Dependencies

- libpng

# Atividades

In a short text format, I describe the work done and project decisions made. For each assignment, there is a corresponding subsection with such descriptions.

## Atividade01

For this assignment, I wrote a function to manage saving images on the disk. I chose primarily PNG encoding when dealing with images, thus using the `libpng` library. To test the save function, I represented some images in a 2D array of 256x256 and used the function `save_image()` to save them into .png files. 

> A load function is yet to be written for use on future assignments.
