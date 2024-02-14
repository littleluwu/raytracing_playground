#include "../import_utils.h"

#include "../Atividade04/Headers/camera.h"
#include "../Atividade04/Headers/color.h"
#include "../Atividade04/Headers/hittable_list.h"
#include "../Atividade04/Headers/sphere.h"
#include "../Atividade05/Headers/material.h"

int main() {
    hittable_list world;

    //Terreno
    auto material_ground = make_shared<lambertian>(color(0.4, 0.7, 0.2));
    world.add(make_shared<triangle>(point3(-1,0,1),point3(-1,0,-1),point3(1,0,-1),material_ground,vec3(0,1,0)));
    world.add(make_shared<triangle>(point3(1,0,-1),point3(1,0,1),point3(-1,0,1),material_ground,vec3(0,1,0)));

    //Semi-Esfera
    auto material_sphere = make_shared<dielectric>(1.15);
    world.add(make_shared<sphere>(point3( 0, 0, 0), 0.4, material_sphere));

    //Pontos do Cubo
    auto mat = make_shared<lambertian>(color(0.4, 0.2, 0.8));
    point3 A = point3(-0.1,0.14,-0.1);
    point3 B = point3(-0.1,0,-0.1);
    point3 C = point3(0.1,0,-0.1);
    point3 D = point3(0.1,0.14,-0.1);

    point3 E = point3(0.1,0.14,0.1);
    point3 F = point3(0.1,0,0.1);
    point3 G = point3(-0.1,0.14,0.1);
    point3 H = point3(-0.1,0,0.1);

    //Face 1 do cubo
    world.add(make_shared<triangle>(A,B,C,mat,vec3(0,0,-1)));
    world.add(make_shared<triangle>(C,D,A,mat,vec3(0,0,-1)));

    //Face 2 do cubo
    world.add(make_shared<triangle>(D,C,F,mat,vec3(1,0,0)));
    world.add(make_shared<triangle>(F,E,D,mat,vec3(1,0,0)));

    //Face 3 do cubo
    world.add(make_shared<triangle>(A,B,H,mat,vec3(-1,0,0)));
    world.add(make_shared<triangle>(H,G,A,mat,vec3(-1,0,0)));

    //Face 4 do cubo
    world.add(make_shared<triangle>(G,H,F,mat,vec3(0,0,1)));
    world.add(make_shared<triangle>(F,E,G,mat,vec3(0,0,1)));


    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth = 45;

    cam.vfov = 60;
    cam.vup = vec3(0,1,0);

    float x = 0.0;
    float z = -0.6;
    float x_rate = 0.03;
    float z_rate = 0.03;

    //Looping de geracao de frames
    for (int i = 0; i < 5*12; i++){
        printf("Rendering Frame %i\n",i);
        cam.lookfrom = point3(x,0.3,z);
        cam.lookat = point3(0,0.05,0);

        char frame[100];
        sprintf(frame,"./output/frame%i.png",i); //Nomeando em ordem crescente
        cam.render(world,frame);
        z += z_rate;
        x -= x_rate;

        if (z == 0.0) x_rate = -x_rate;
        if (z == 0.6) z_rate = -z_rate;
    }
}