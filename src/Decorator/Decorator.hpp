/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** calcs
*/

#ifndef DecoratorRATOR_HPP_
#define DecoratorRATOR_HPP_

#include "Scene.hpp"
#include "IDecorator.hpp"
#include "Ray.hpp"
#include "IMaterial.hpp"

class Decorator : public IDecorator {
public:
    Decorator(Scene scene);
    ~Decorator();
    void loop(Scene scene);
    Vec3 colorloop(const Ray &r, const std::vector<std::shared_ptr<IHitable>> &_objects, Light _light);

private:
    std::vector<std::shared_ptr<IHitable>> _world;
    Light _light;
    Camera _cam;
    int _width;
    int _height;
    int _ns;
};

#endif
