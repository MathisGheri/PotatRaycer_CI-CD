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
        Light(const Vec3& pos, float intensity, Vec3 n, bool d);
        ~Light();
        Vec3 getPosition() const;
        float getIntensity() const;
        Vec3 calculateLightDirection(const Vec3& point) const;
        bool isDirec();
        Vec3 getNormal();
    private:
        Vec3 position;
        float intensity;
        Vec3 normal;
        bool direc;
};

#endif /* !LIGHT_HPP_ */

