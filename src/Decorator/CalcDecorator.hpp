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

class calcdeco : public IDecorator {
    public:
        calcdeco(Scene *scene);
        ~calcdeco();
        void loop();
        Vec3 colorloop(const Ray &r, std::vector<std::unique_ptr<IHitable>> _world, std::unique_ptr<Light> _light);

    private:
        std::vector<std::unique_ptr<IHitable>> _world;
        std::unique_ptr<Light> _light;
        // Light _lig;
        std::unique_ptr<Camera> _cam;
        // Camera _camera;
        int _width;
        int _height;
        int _ns = 200;
};


#endif
