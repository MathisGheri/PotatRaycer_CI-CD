/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** ILight
*/

/**
* @file AmbiantLight.hpp
* @brief AmbiantLight class header file.
*/

#ifndef AMBIANTLIGHT_HPP_
#define AMBIANTLIGHT_HPP_

#include "ILight.hpp"

/**
* @class AmbiantLight
* @brief Class used to create the AmbiantLight.
*/

class AmbiantLight : public ILight {
    public:

        /**
        * @brief Construct a new Ambiant Light object
        * @param position The position of the light.
        * @param intensity The intensity of the light.
        */
        AmbiantLight(Vec3 position, float intensity);
        ~AmbiantLight();
        std::string getType() override final;
        float getIntensity() const override final;
        Vec3 getPosition() const override final;
        Vec3 calculateLightDirection(const Vec3& point) const override final;
        Vec3 getNormal() override final;
        float getSize() override final;
    private:
        std::string _type = "ambiant";
        Vec3 position;
        float intensity;
};

#endif /* !AMBIANTLIGHT_HPP_ */