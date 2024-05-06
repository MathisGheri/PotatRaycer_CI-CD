/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Scene
*/

#include "Scene.hpp"
#include "SingletonLogger.hpp"

Scene::Scene()
{
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "LOG: Scene created.";
	logger->log(INFO, msg.str());
}

Scene::~Scene()
{
    this->objects.clear();
}

void Scene::setLight(Light l)
{
    this->light = l;
}

void Scene::setCamera(Camera c)
{
    this->camera = c;
}

void Scene::addObject(std::shared_ptr<IHitable> obj)
{
    objects.push_back(obj);
}

const std::vector<std::shared_ptr<IHitable>>& Scene::getObjects() const
{
    return objects;
}

const Light &Scene::getLight(void) const
{
    return this->light;
}

const Camera &Scene::getCamera(void) const
{
    return this->camera;
}
