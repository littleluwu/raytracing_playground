#include "../../import_utils.h"

#include "../../Atividade04/Headers/camera.h"
#include "../../Atividade04/Headers/color.h"
#include "../../Atividade04/Headers/hittable_list.h"
#include "../../Atividade04/Headers/sphere.h"
#include "../../Atividade05/Headers/material.h"


int main() {
    hittable_list world;

    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));


    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5, material_center));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;


    cam.render(world,"./output/diffuse_sphere.png");
}