# :pencil2:- Atividade06 - Metal and Dieletrics

We continue the work on materials, adding different ways for the rays to interact. The first material is the `Metal`, experimenting with specular reflection following the [Chapter 10](https://raytracing.github.io/books/RayTracingInOneWeekend.html#metal). The refraction, where the ray goes through the object with a slight distortion, we coded on the `Dielectric` class using the [Chapter 11](https://raytracing.github.io/books/RayTracingInOneWeekend.html#dielectrics) as a base.

In this assignment, we also further enhanced the camera class so the World Coordinate System is detached from the Camera Coordinate System. We can have setups of multiple cameras on a scene now. With this, we conclude the learning of basic knowledge on raytracing as this is the final assignment.

## :test_tube: Unit Tests

We tested the materials by rendering a sample scene with spheres, adding each material created along the project, and observing their interactions in the environment.

- A dielectric sphere, a diffuse sphere, and a metal sphere.

![Materials and Spheres](/Atividade06/Test/output/materials_spheres.png)

For testing the added camera properties of focus point and origin, we rendered the same scene with the materials sphere from a different point of view.

- A distant shot of the three spheres.

![Materials and Spheres](/Atividade06/Test/output/spheres_distant.png)