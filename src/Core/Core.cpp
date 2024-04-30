/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(){} //put la scene to nullptr

Core::~Core(){}

void Core::loadConfigFromFile(std::string filename)
{
    //load from the file
}

void Core::assembleScene(/*tableau de la config*/)
{
    SceneBuilder *sceneBuilder = new SceneBuilder();
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
    //add all the mat
}

Scene *Core::getScene()
{
    return this->scene;
}
