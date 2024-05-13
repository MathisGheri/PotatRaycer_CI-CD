/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** DirectionalLight
*/

/**
* @file DirectionalLight.hpp
* @brief File for the DirectionalLight class. 
*/

#ifndef DIRECTIONALLIGHT_HPP_
#define DIRECTIONALLIGHT_HPP_

#include "ILight.hpp"

/**
* @class DirectionalLight
* @brief Class used to create the DirectionalLight.
*/

class DirectionalLight : public ILight {
    public:
        /**
        * @brief Construct a new Directional Light object
        * @param position The position of the light.
        * @param intensity The intensity of the light.
        * @param normal The normal of the light.
        * @param size The size of the light.
        */
        DirectionalLight(Vec3 position, float intensity, Vec3 normal, float size);
        ~DirectionalLight();
        std::string getType() override final;
        Vec3 getPosition() const override final;
        float getIntensity() const override final;
        Vec3 calculateLightDirection(const Vec3& point) const override final;
        Vec3 getNormal() override final;
        float getSize() override final;
    private:
        std::string _type = "directional";
        Vec3 position;
        float intensity;
        Vec3 normal;
        float size;
};

#endif /* !DIRECTIONALLIGHT_HPP_ */