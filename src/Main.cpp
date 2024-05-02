/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Main
*/

#include "include.hpp"
#include "Core.hpp"
#include "Logger.hpp"
#include "SingletonLogger.hpp"
#include "Exception.hpp"

int main(int argc, char **argv)
{
    try {
        throw Exception("Une erreur spécifique s'est produite!", Level::MIDDLE);
    } catch (const Exception& e) {
        std::cout << "Exception capturée: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Autre exception std: " << e.what() << std::endl;
    }
    //try // expect
    if (argc >= 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-potat") == 0)) { //changer pour du cpp
        printf("./Raytracer --help\nUSAGE: ./Raytracer <SCENE_FILE>\nSCENE_FILE: scene configuration\n");
        exit(0);
    } else if (argc > 2) {
        exit(84);
    }
    /**********************/
    try {
        Logger* logger = LoggerSingleton::getInstance();
        logger->log(INFO, "Application started");
        const std::string &file = argv[1];
        Core core;
        core.assembleScene(file);
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
