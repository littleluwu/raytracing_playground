# :pencil2:- Atividade04 - Rendering Shapes

We started playing with raytracing in this assignment. Following chapters 4, 5, and 6 from the book Ray Tracing in One Weekend, we implemented classes for the rays, camera, shapes, and others to render the first object on the screen.

To render 3D models using the class defined from the previous assignment, we created a triangle shape class to depict the polygon meshes by breaking them into triangles. To calculate whether the ray has hit the triangle or didn't hit at all, we used the concept of barycentric coordinates to render the triangle. The `hit` function, presented in the triangle class, we implemented it using the [Raytracing: Rendering a Triangle](https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/why-are-triangles-useful.html) lesson as a base for calculating the barycentric coordinates.

## :test_tube: Unit Tests

For testing the code, we rendered three images with different objects: an image with spheres, an image with one triangle, and an image of a 3D model obtained from [Free3D](https://free3d.com/3d-model/triangle-v1--412452.html), made by the user **printable_models**.

- A sphere colored using the normals.

![Colored Sphere](/Atividade04/Test/output/sphere.png)

- A black triangle.

![Blue Purple Triangle](/Atividade04/Test/output/triangle.png)

- The 3D object of a hollow triangle sign.

![3D hollow triangle sign](/Atividade04/Test/output/model.png)

The model was composed of a mesh of quadrilaterals. We break the quadrilaterals into two triangles when adding the faces to the world of objects, thus rendering the model on a mesh of triangles. To place the 3D model directly in the camera's view, we listed the implementation of some functions for transforming the object as an addition for future assignments.