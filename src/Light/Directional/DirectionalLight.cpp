/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"

DirectionalLight::~DirectionalLight()
{
}

DirectionalLight::DirectionalLight(Vec3 position, float intensity, Vec3 normal, float size) : position(position), intensity(intensity), normal(normal), size(size)
{
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "Log: Directional Light created with parameters pos = " << position << ", i = " << intensity << ", normal" << normal << ", with size of " << size << ".";
	logger->log(INFO, msg.str());
}

std::string DirectionalLight::getType()
{
    return _type;
}

Vec3 DirectionalLight::getPosition() const
{
    return position;
}

float DirectionalLight::getIntensity() const
{
    return intensity;
}

Vec3 DirectionalLight::calculateLightDirection(const Vec3& point) const
{
    return unit_vector(position - point);
}

Vec3 DirectionalLight::getNormal()
{
    return normal;
}

float DirectionalLight::getSize()
{
    return size;
}
