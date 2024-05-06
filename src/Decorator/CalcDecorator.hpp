/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** calcs
*/

#ifndef CALCDECORATOR_HPP_
#define CALCDECORATOR_HPP_

#include "Scene.hpp"
#include "IDecorator.hpp"
#include "Ray.hpp"
#include "IMaterial.hpp"

class Calcdeco : public IDecorator {
public:
    Calcdeco(Scene *scene);
    ~Calcdeco();
    void loop(Scene *scene);
    Vec3 colorloop(const Ray &r, const std::vector<IHitable*> & _world, Light* _light);

private:
    std::vector<IHitable*> _world;
    Light* _light;
    Camera* _cam;
    int _width;
    int _height;
    int _ns = 200;
};

#endif
