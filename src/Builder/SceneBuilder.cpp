/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** SceneBuilder
*/

#include "SceneBuilder.hpp"

SceneBuilder::SceneBuilder()
{
    if (scene != nullptr)
            delete scene;
    scene = new Scene();
}

SceneBuilder::~SceneBuilder()
{
    //delete light/camera etc
}

void SceneBuilder::createLight()
{
    Light *light = new Light();
    scene->setLight(light);
}

void SceneBuilder::createCamera()
{
    Camera *camera = new Camera();
    scene->setCamera(camera); 
}

void SceneBuilder::createObject(Hitable *object) //on sait pas encore ce qu'on va avoir
{
    //créér
    Hitable *object = createObj(); //envoyer les données
    scene->addObject(object);    
}

void SceneBuilder::getScene()
{
    return scene;
}
