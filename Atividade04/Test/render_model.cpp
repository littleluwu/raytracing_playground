#include "../../import_utils.h"

#include "../Headers/camera.h"
#include "../Headers/hittable_list.h"
#include "../Headers/triangle.h"


int main() {
    hittable_list world;

    object3D triangle_key("triangle_v1.obj");
    object3D bench("../../Atividade03/test/bench.obj");

    world = triangle_key.add_to_world(world);
    //world = bench.add_to_world(world);
    //world.add(make_shared<triangle>(point3(0.7,0.7,-1),point3(0.7,-0.7,-1),point3(-0.7,-0.7,-1)));
    //world.add(make_shared<triangle>(point3(0.7,0.7,-1),point3(-0.7,0.7,-1),point3(-0.7,-0.7,-1)));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;

    cam.render(world,"./output/model.png");
}