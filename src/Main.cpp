/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Main
*/

/**
* @file Main.cpp
* @brief Main file.
*/

#include "include.hpp"
#include "Core.hpp"
#include "SingletonLogger.hpp"
#include "Exception.hpp"
#include "FileWatcherSingleton.hpp"

int main(int argc, char **argv)
{
    if (argc >= 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-potat") == 0)) { //changer pour du cpp
        printf("./Raytracer --help\nUSAGE: ./Raytracer <SCENE_FILE>\nSCENE_FILE: scene configuration\n");
        exit(0);
    } else if (argc > 2) {
        exit(84);
    }
    /**********************/
    Logger *logger = LoggerSingleton::getInstance();
    FileWatcher *watcher = FileWatcherSingleton::getInstance();
    watcher->setFileToWatch(argv[1]);
    try {
        logger->log(INFO, "Application started.");
        const std::string &file = argv[1];
        Core core;
        core.assembleScene(file);
        logger->log(INFO, "Initialisation ended.");
        core.generatePPM();
    } catch (const Exception& e) {
        std::cout << "Exception captured: " << e.what() << ". With Level: ";
        switch (e.getLevel()) {
            case Level::LOW:
                std::cout << "low";
                break;
            case Level::MIDDLE:
                std::cout << "middle";
                break;
            case Level::HIGH:
                std::cout << "HIGH";
                break;
        }
        std::cout << std::endl;
        return 84;
    }
    logger->log(INFO, "Application Stopped.\n");
    return 0;
}
