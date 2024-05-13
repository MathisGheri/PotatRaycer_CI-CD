/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** ILight
*/

/**
* @file ILight.hpp
* @brief ILight class header file.
*/

#pragma once

#ifndef ILIGHT_HPP_
#define ILIGHT_HPP_

#include "Vec3.hpp"
#include "include.hpp"
#include "SingletonLogger.hpp"

/**
* @class ILight
* @brief Interface for the Light class.
*/

class ILight {
    public:
        virtual ~ILight() = default;

        /**
        * @brief Get the type of the light.
        * @return The type of the light.
        */
        virtual std::string getType() = 0;

        /**
        * @brief Get the position of the light.
        * @return The position of the light.
        */ 
        virtual Vec3 getPosition() const = 0;

        /**
        * @brief Get the intensity of the light.
        * @return The intensity of the light.
        */
        virtual float getIntensity() const = 0;

        /**
        * @brief Function to calculate the light direction.
        * @param point The point.
        * @return The light direction.
        */
        virtual Vec3 calculateLightDirection(const Vec3& point) const = 0;

        /**
        * @brief Function to get the normal of the light.
        * @return The normal of the light.
        */
        virtual Vec3 getNormal() = 0;

        /**
        * @brief Function to get the size of the light.
        * @return The size of the light.
        */
        virtual float getSize() = 0;
};

#endif /* !ILIGHT_HPP_ */
