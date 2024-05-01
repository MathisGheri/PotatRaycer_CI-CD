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
        printf("./raytracer --help\nUSAGE: ./raytracer <SCENE_FILE>\nSCENE_FILE: scene configuration\n");
        exit(0);
    } else if (argc > 2) {
        exit(84);
    }
    return 0;
}
