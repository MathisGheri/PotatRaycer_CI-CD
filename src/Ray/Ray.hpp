/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Ray
*/

#pragma once

#ifndef Ray_HPP_ 
#define Ray_HPP_

#include "Vec3.hpp"

class Ray {
    public:
        Ray();
        ~Ray();
        Ray(const Vec3& a, const Vec3 &b);
        Vec3 origin() const;
        Vec3 direction() const;
        Vec3 point_at_parameter(float t) const;

    private:
        Vec3 A;
        Vec3 B;
};

#endif /* !Ray_HPP_ */