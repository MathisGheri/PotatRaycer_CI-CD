/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Scene
*/

#include "Scene.hpp"

Scene::Scene()
{
    this->camera = nullptr;
    this->light = nullptr;
}

Scene::~Scene()
{
    delete(this->camera);
    delete(this->light);
    this->Objects.clear();
}

void Scene::setLight(Light *l)
{
    this->light = l;
}

void Scene::setCamera(Camera *c)
{
    this->camera = c;
}

void Scene::addObject(IHitable *obj)
{
    this->Objects.push_back(obj);
}

std::vector<IHitable *> Scene::getObjects(void)
{
    return this->Objects;
}

Light *Scene::getLight(void)
{
    return this->light;
}

Camera *Scene::getCamera(void)
{
    return this->camera;
}
