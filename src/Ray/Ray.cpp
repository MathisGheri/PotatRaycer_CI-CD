/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Ray
*/

/**
* @file Ray.cpp
* @brief Class for handling rays.
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

Ray::Ray(const Vec3 &a, const Vec3 &b) : origin(a), direction(b)
{
    // Logger *logger = LoggerSingleton::getInstance();
	// std::ostringstream msg;
    // msg << "LOG: Ray created with these params. a = " << a << ", b = " << b << ".";
	// logger->log(INFO, msg.str());
}

Vec3 Ray::getOrigin() const
{
    return origin;
}

Vec3 Ray::getDirection() const
{
    return direction;
}

Vec3 Ray::point_at_parameter(float t) const
{
    return origin + (t * direction); //va falloir implémenter cette op
}
