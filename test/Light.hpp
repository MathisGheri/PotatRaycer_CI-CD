/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Light
*/
#pragma once

#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "Vec3.hpp"

class Light {
    public:
        Light() = default;
        Light(const Vec3& pos, float intensity);
        ~Light();
        Vec3 getPosition() const;
        float getIntensity() const;
        Vec3 calculateLightDirection(const Vec3& point) const;
    private:
        Vec3 position;
        float intensity;
};

Light::Light(const Vec3& pos, float intensity) : position(pos), intensity(intensity)
{
}

Light::~Light()
{
}

Vec3 Light::getPosition() const
{
    return position;
}

float Light::getIntensity() const
{
    return intensity;
}

Vec3 Light::calculateLightDirection(const Vec3& point) const
{
    return unit_vector(position - point);
}


#endif /* !LIGHT_HPP_ */
