/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Vec2
*/

#pragma once

#ifndef Vec2_HPP_
#define Vec2_HPP_

class Vec2 {
    public:
        Vec2() {}
        Vec2(float e0, float e1)
        {
            e[0] = e0; e[1] = e1;
        }
        Vec2 operator*(float scalar) const {
            return Vec2(e[0] * scalar, e[1] * scalar);
        }

        // Addition de deux Vec2
        Vec2 operator+(const Vec2& other) const {
            return Vec2(e[0] + other.e[0], e[1] + other.e[1]);
        }
        float e[2];
    private:
};

#endif /* !Vec2_HPP_ */