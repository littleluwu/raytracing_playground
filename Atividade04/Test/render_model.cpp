#include "../../import_utils.h"

#include "../Headers/camera.h"
#include "../Headers/hittable_list.h"
#include "../Headers/triangle.h"


int main() {
    hittable_list world;

    object3D triangle_key("triangle_v1.obj");
    //object3D bench("../../Atividade03/test/bench.obj");

    auto mat = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    world = triangle_key.add_to_world(world,mat);

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;


    cam.render(world,"./output/model.png");
}