/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Ray
*/

/**
* @file Ray.hpp
* @brief Class for handling rays.
*/

#pragma once

#ifndef Ray_HPP_ 
#define Ray_HPP_

#include "Vec3.hpp"

/**
* @class Ray
* @brief Class for handling rays.
*/

class Ray {
    public:
        Ray();
        ~Ray();

        /**
        * @brief Construct a new Ray object
        */
        Ray(const Vec3& a, const Vec3 &b);

        /**
        * @brief Get the Origin object
        * @return Vec3 
        */
        Vec3 getOrigin() const;

        /**
        * @brief Get the Direction object
        * @return Vec3 
        */
        Vec3 getDirection() const;

        /**
         * @brief Get the Point At Parameter object.
         * @param t This is usually a scalar value.
         * @return Vec3 The point on the line (or ray) at the specified parameter `t`. 
         *         The return value is a 3D vector (Vec3) representing the coordinates 
         *         of the point in 3D space.
         */
        Vec3 point_at_parameter(float t) const;


    private:
        Vec3 origin;
        Vec3 direction;
};

#endif /* !Ray_HPP_ */
