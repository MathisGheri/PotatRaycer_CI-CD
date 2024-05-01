/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Main
*/

#include <iostream>
#include <string.h>

int main(int argc, char **argv)
{
    //try // expect
    if (argc >= 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-potat") == 0)) { //changer pour du cpp
        printf("./Raytracer --help\nUSAGE: ./Raytracer <SCENE_FILE>\nSCENE_FILE: scene configuration\n");
        exit(0);
    } else if (argc > 2) {
        exit(84);
    }
    /**********************/
    try {
        //Parser
        //SceneBuilder
        //Scene
        //Calcul
        //Rendu
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        //free destroy delete etc..
        return 84;
    }
    return 0;
}

/*Code Kyliann*/

    // int width = 800;
    // int height = 400;
    // int ns = 100;
    // std::cout << "P3\n" << width << " " << height << "\n255\n";
    // sdltemplate::sdl("POTATX", width, height);
    // sdltemplate::loop();
    // hitable *list[5]; //list = scÃ¨ne
    // list[0] = new sphere(Vec3(0, 0, -1), 0.5, new lambertian(Vec3(0.1, 0.2, 0.5)));
    // list[1] = new sphere(Vec3(0, -100.5, -1), 100, new lambertian(Vec3(0.8, 0.8, 0.0)));
    // list[2] = new sphere(Vec3(1, 0, -1), 0.5, new metal(Vec3(0.8, 0.6, 0.2), 0));
    // // list[2] = new sphere(Vec3(1, 0, -1), 0.5, new metal(Vec3(0.8, 0.6, 0.2), 0.2));
    // list[3] = new sphere(Vec3(-1, 0, -1), 0.5, new metal(Vec3(0.8, 0.8, 0.8), 0));
    // // list[3] = new sphere(Vec3(-1, 0, -1), 0.5, new dielectric(1.5));
    // // list[4] = new sphere(Vec3(-1, 0, -1), -0.45, new dielectric(1.5));
    // hitable *world = new hitable_list(list, 4);
    // // hitable *list[2];
    // // float R = cos(M_PI/4);
    // // list[0] = new sphere(Vec3(-R, 0, -1), R, new lambertian(Vec3(0, 0, 1)));
    // // list[1] = new sphere(Vec3(R, 0, -1), R, new lambertian(Vec3(1, 0, 0)));
    // // hitable *world = new hitable_list(list, 2);
    // // camera cam;
    // // Vec3 lookfrom(3, 3, 2);
    // Vec3 lookfrom(0, 0, 0);
    // Vec3 lookat(0, 0, -1);
    // float dist_to_focus = (lookfrom - lookat).length();
    // // float aperture = 2.0;
    // float aperture = 0;
    // camera cam(lookfrom, lookat, Vec3(0, 1, 0), 90, float(width) / float(height), aperture, dist_to_focus);
    // for (int y = height - 1; y >= 0; y--) {
    //     for (int x = 0; x < width; x++) {
    //         Vec3 col(0, 0, 0);
    //         for (int s = 0; s < ns; s++) {
    //             float u = float(x + drand48()) / float(width);
    //             float v = float(y + drand48()) / float(height);
    //             Ray r = cam.get_Ray(u, v);
    //             Vec3 p = r.point_at_parameter(2.0);
    //             col += color(r, world, 0);
    //         }
    //         col /= float(ns);
    //         col = Vec3(sqrt(col.r()), sqrt(col.g()), sqrt(col.b()));
    //         int ir = int(255.99 * col[0]);//color
    //         int ig = int(255.99 * col[1]);
    //         int ib = int(255.99 * col[2]);
    //         std::cout << ir << " " << ig << " " << ib << "\n";
    //         sdltemplate::setDrawColor(sdltemplate::createColor(ir, ig, ib, 255));
    //         sdltemplate::drawPoint(x, height - y);
    //     }
    //     if ((y % (height / 10)) == 0)
    //         sdltemplate::loop();
    // }