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
        Vec3 getOrigin() const;
        Vec3 getDirection() const;
        Vec3 point_at_parameter(float t) const;

    private:
        Vec3 origin;
        Vec3 direction;
};

#endif /* !Ray_HPP_ */
