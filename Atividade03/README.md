# :pencil2:- Atividade03 - Load 3D Object

For this assignment, I created a class called `object3D` that describes 3D objects, storing their important components like vertices and faces in vector structures. The objec3D constructor expects a file path as an argument that points to an `OBJ` file containing the description of the geometry of a given model you want to load. It only loads an object from a .obj file, being the only geometry definition format accepted.

Additionally, the class contains functions for retrieving information of the model in a faster way.

Additionally, the class contains functions for retrieving information about the model quickly.

Given how the `strtok()` function works, it ignores empty tokens. A problem I face when dealing with .obj files is when the model contains faces with vertices and normals coordinates but no texture, being represented in the file as `vertex//vertex normal`. As a solution, I used an alternate implementation of the `strtok()` function to catch those empty tokens when reading face data. The alternate version was made by the user **Scheff's Cat** as a solution for a [question](https://stackoverflow.com/questions/42315585/split-string-into-tokens-in-c-when-there-are-2-delimiters-in-a-row) on the StackOverflow forum.

I tested the class implementation by loading a bench model and checking if the vertices and coordinates were loaded correctly. The model used in this test was gathered from the site [Free3D]( https://free3d.com/pt/3d-model/bench-84662.html), made by the user **raccoonice**.





## :test_tube: Unit Tests

- Bench model load: 7/7 :white_check_mark: