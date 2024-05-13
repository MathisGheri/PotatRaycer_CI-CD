/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Vec2
*/

/**
* @file Vec2.hpp
* @brief Vec2 class header file.
*/

#pragma once

#ifndef Vec2_HPP_
#define Vec2_HPP_

/**
* @class Vec2
* @brief Class for representing a 2D vector.
*
* The Vec2 class provides basic operations for 2-dimensional vectors, including
* initialization, scaling, and addition.
*/
class Vec2 {
    public:
        /**
         * @brief Default constructor for Vec2.
         *
         * Initializes the vector with zero values.
         */
        Vec2() : e{0.0f, 0.0f} {}

        /**
         * @brief Parameterized constructor for Vec2.
         * 
         * @param e0 The x-coordinate of the vector.
         * @param e1 The y-coordinate of the vector.
         */
        Vec2(float e0, float e1) {
            e[0] = e0;
            e[1] = e1;
        }

        /**
         * @brief Multiplies the vector by a scalar.
         * 
         * @param scalar The scalar value to multiply with.
         * @return Vec2 The resulting vector after multiplication.
         */
        Vec2 operator*(float scalar) const {
            return Vec2(e[0] * scalar, e[1] * scalar);
        }

        /**
         * @brief Adds two Vec2 vectors.
         * 
         * @param other The other vector to add.
         * @return Vec2 The resulting vector after addition.
         */
        Vec2 operator+(const Vec2& other) const {
            return Vec2(e[0] + other.e[0], e[1] + other.e[1]);
        }

        float e[2]; ///< Array storing the x and y coordinates of the vector.

    private:
};

#endif /* !Vec2_HPP_ */
