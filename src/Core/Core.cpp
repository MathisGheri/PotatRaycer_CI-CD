/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Core
*/

#include "Core.hpp"

Core::Core()
{
    this->scene = nullptr;
}

Core::~Core(){}

void Core::assembleScene(const std::string &filename)
{
    SceneBuilder sceneBuilder();
    Parsing parser(filename);
    sceneBuilder.createCamera(parser.GetCamera());
    sceneBuilder.createLight(parser.getLights());
    sceneBuilder.createObjects(parser.getPrimitives());
    //faire un appel à parsing
    //mettre la cam
    //mettre la light
    //mettre les objects//primitives//hitables
    //iterate through the list
    this->scene = sceneBuilder->getScene();
}

void Core::generatePPM()
{
    //calcul
}

Scene *Core::getScene()
{
    return this->scene;
}
