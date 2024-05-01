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
    //delete(this->scene);
    //delete light/camera etc
}

void SceneBuilder::createLight()
{
    Light *light = new Light();
    scene->setLight(light);
    //delete light
}

void SceneBuilder::createCamera()
{
    Camera *camera = new Camera(); //good argument
    scene->setCamera(camera);
    //delete camera ?
}

void SceneBuilder::createObject(IHitable *object) //on sait pas encore ce qu'on va avoir
{
    //créér + loop ptet faire gaffe à si on a un getSphere ou un getPlan etc..
    IHitable *object = createObj(); //envoyer les données pour vérifier quel primitives c'est
    scene->addObject(object);    
}

Scene *SceneBuilder::getScene()
{
    return this->scene;
}
