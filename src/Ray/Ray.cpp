/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Ray
*/

#include "Ray.hpp"

Ray::Ray()
{
}

Ray::~Ray()
{
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
