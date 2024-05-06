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

#endif /* !LIGHT_HPP_ */

