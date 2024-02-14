# :pencil2:- Atividade05 - Diffuse Materials

At this point in the class, we learned to render basic shapes and more complex models described by a mesh of polygons. For this assignment, we deal with object materials to let the rays interact with the objects in the environment. The first ray interaction we implemented was the diffuse reflection, also called Lambertian reflection. 

We used the calculations of the diffused rays presented in the [Chapter 9](https://raytracing.github.io/books/RayTracingInOneWeekend.html#diffusematerials) of the book series. [Chapter 7](https://raytracing.github.io/books/RayTracingInOneWeekend.html#movingcameracodeintoitsownclass) and [Chapter 8](https://raytracing.github.io/books/RayTracingInOneWeekend.html#antialiasing) where implemented as well, moving the camera to its class and adding anti-aliasing when rendering the borders of 3D models.

In the previous assignment, we listed the need for functions to manipulate the vertices of 3D objects and place them into the world. We implemented some routines in the `object3D` class to simplify this process. The class now has a move function, three rotate functions (one for each axis), and a scale function.

## :test_tube: Unit Tests

With the intent of testing the diffuse reflection, we rendered the sphere scene from the previuous assingment, adding the new material onto the spheres placed in the world.

- Diffuse spheres

![Diffuse Spheres](/Atividade05/Test/output/diffuse_sphere.png)

To test the implementation of field-of-view (FOV) in the camera class, we rendered a close shot of the diffuse sphere using a reduced FOV.

![Reduced FOV](/Atividade05/Test/output/sphere_lowfov.png)