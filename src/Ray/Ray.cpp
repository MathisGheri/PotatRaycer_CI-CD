/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Ray
*/

#include "Ray.hpp"

Ray::Ray()
{
    // Logger *logger = LoggerSingleton::getInstance();
	// std::ostringstream msg;
    // msg << "LOG: Ray created without params.";
	// logger->log(DEBUG, msg.str());
}

Ray::~Ray()
{
}

Ray::Ray(const Vec3 &a, const Vec3 &b) : A(a), B(b)
{
    // Logger *logger = LoggerSingleton::getInstance();
	// std::ostringstream msg;
    // msg << "LOG: Ray created with these params. a = " << a << ", b = " << b << ".";
	// logger->log(INFO, msg.str());
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
