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

Core::Core()
{
    this->scene = nullptr;
    std::cout<<"Log: Core was created."<< std::endl;
    Logger* logger = LoggerSingleton::getInstance();
    logger->log(INFO, "Core Created");
}

Core::~Core(){}

void Core::assembleScene(const std::string &filename)
{
    SceneBuilder sceneBuilder;
    Parsing parser(filename);
    sceneBuilder.createCamera(parser.GetCamera());
    sceneBuilder.createLight(parser.getLights());
    sceneBuilder.createObjects(parser.getPrimitives());
    this->scene = sceneBuilder.getScene();
}

void Core::generatePPM()
{
    //calcul
}

Scene *Core::getScene()
{
    return this->scene;
}
