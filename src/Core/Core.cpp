/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Core
*/

#include "Core.hpp"
#include "SceneBuilder.hpp"
#include "Parsing.hpp"
#include "SingletonLogger.hpp"
#include "Computing.hpp"
#include "Exception.hpp"

Core::Core()
{
    scene = Scene();
    Logger* logger = LoggerSingleton::getInstance();
    logger->log(INFO, "Core Created.");
}

Core::~Core(){}

void Core::assembleScene(const std::string &filename)
{
    Logger* logger = LoggerSingleton::getInstance();
    SceneBuilder sceneBuilder;
    Parsing parser(filename);
    logger->log(DEBUG, "Parsing done.");
    sceneBuilder.createCamera(parser.GetCamera());
    logger->log(DEBUG, "Camera created.");
    sceneBuilder.createLight(parser.getLights());
    logger->log(DEBUG, "Light created.");
    sceneBuilder.createPrimitives(parser.getPrimitives());
    logger->log(DEBUG, "Primitives Created.");
    this->scene = sceneBuilder.getScene();
}

void Core::generatePPM()
{
    Compute deco = Compute(this->getScene());
    try {
        deco.loop(this->getScene());
    } catch(const Exception& e) {
        std::cout << e.what() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        FileWatcher *watcher = FileWatcherSingleton::getInstance();
        this->assembleScene(watcher->getFile());
        this->generatePPM();
    }
}

const Scene &Core::getScene() const
{
    return this->scene;
}
