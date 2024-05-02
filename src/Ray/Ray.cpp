/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Ray
*/

#include "Ray.hpp"

Ray::Ray()
{
    std::cout << "LOG: Ray was created without params" << std::endl;
}

Ray::~Ray()
{
}

Ray::Ray(const Vec3 &a, const Vec3 &b)
{
    this->A = a;
    this->B = b;
    std::cout << "LOG: Ray was created with these params. a = " << a << ", b = " << b << std::endl;
}

Vec3 Ray::origin() const
{
    return A;
}

Vec3 Ray::direction() const
{
    return B;
}

Vec3 Ray::point_at_parameter(float t) const
{
    return A + t * B; //va falloir implémenter cette op
}
