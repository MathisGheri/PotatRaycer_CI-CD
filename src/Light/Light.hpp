/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Light
*/

#include "Vec3.hpp"
#include "Physics.hpp"

#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#pragma once

class Light {
    public:
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

