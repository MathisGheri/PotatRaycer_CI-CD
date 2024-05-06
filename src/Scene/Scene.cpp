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
    this->camera = nullptr;
    this->light = nullptr;
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "LOG: Scene created.";
	logger->log(INFO, msg.str());
}

Scene::~Scene()
{
    this->Objects.clear();
}

void Scene::setLight(std::unique_ptr<Light> l)
{
    this->light = std::move(l);
}

void Scene::setCamera(std::unique_ptr<Camera> c)
{
    this->camera = std::move(c);
}

void Scene::addObject(std::unique_ptr<IHitable> obj)
{
    Objects.push_back(std::move(obj));
}

std::vector<std::unique_ptr<IHitable>>& Scene::getObjects(void)
{
    return this->Objects;
}

std::unique_ptr<Light> Scene::getLight(void)
{
    return std::move(light);
}

std::unique_ptr<Camera> Scene::getCamera(void)
{
    return std::move(camera);
}
