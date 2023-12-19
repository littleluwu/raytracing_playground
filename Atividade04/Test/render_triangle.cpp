#include "../../import_utils.h"

#include "../Headers/camera.h"
#include "../Headers/hittable_list.h"
#include "../Headers/triangle.h"


int main() {
    hittable_list world;

    world.add(make_shared<triangle>(point3(0,4,-5),point3(-5,-3,-5),point3(5,-3,-5)));
    //world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;

    cam.render(world,"./output/triangle.png");
}