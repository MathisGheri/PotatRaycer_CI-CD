/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** ILight
*/

#ifndef AMBIANTLIGHT_HPP_
#define AMBIANTLIGHT_HPP_

#include "ILight.hpp"

class AmbiantLight : public ILight {
    public:
        AmbiantLight(Vec3 position, Vec3 intensity) : position(position), intensity(intensity.x) {}
        ~AmbiantLight();
        std::string getType() { return _type; }
    private:
        std::string _type = "ambiant";
        Vec3 position;
        float intensity;
        Vec3 normal;
        bool direc;
        float size;
};

#endif /* !AMBIANTLIGHT_HPP_ */