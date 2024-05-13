/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** AmbiantLight
*/

#include "AmbiantLight.hpp"

AmbiantLight::~AmbiantLight()
{
}

AmbiantLight::AmbiantLight(Vec3 position, float intensity) : position(position), intensity(intensity)
{
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "Log: Ambiant Light created with parameters pos = " << position << ", i = " << intensity << ".";
	logger->log(INFO, msg.str());
}

std::string AmbiantLight::getType()
{
    return _type;
}

Vec3 AmbiantLight::getPosition() const
{
    return position;
}

float AmbiantLight::getIntensity() const
{
    return intensity;
}

Vec3 AmbiantLight::calculateLightDirection(const Vec3& point) const
{
    return unit_vector(position - point);
}

Vec3 AmbiantLight::getNormal()
{
    return Vec3(0, 0, 0);
}

float AmbiantLight::getSize()
{
    return 0;
}
