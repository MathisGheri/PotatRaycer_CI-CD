/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Ray
*/

#include "../Vec3/Vec3.hpp"

#ifndef RAY_HPP_
#define RAY_HPP_

class Ray {
    public:
        Ray();
        ~Ray();
        Vec3 origin() const;
        Vec3 direction() const;
        Vec3 point_at_parameter(float t) const;

    private:
        Vec3 A;
        Vec3 B;
};

#endif /* !RAY_HPP_ */
