#include "../../import_utils.h"

#include "../Headers/camera.h"
#include "../Headers/hittable_list.h"
#include "../Headers/triangle.h"


int main() {
    hittable_list world;
    auto mat = make_shared<lambertian>(color(0.2, 0.8, 0.2));
    world.add(make_shared<triangle>(point3(0,4,-5),point3(-5,-3,-5),point3(5,-3,-5),mat,vec3(0,0,0)));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;

    cam.render(world,"./output/triangle.png");
}