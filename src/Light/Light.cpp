/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Light
*/

#include "Light.hpp"
#include "Logger.hpp"

Light::Light(const Vec3& pos, float intensity) : position(pos), intensity(intensity)
{
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "Log: Light created with parameters pos = " << pos << ", i = " << intensity << ".";
	logger->log(INFO, msg.str());
}

Light::~Light()
{
}

Vec3 Light::getPosition() const
{
    return position;
}

float Light::getIntensity() const
{
    return intensity;
}

Vec3 Light::calculateLightDirection(const Vec3& point) const
{
    return unit_vector(position - point);
}
