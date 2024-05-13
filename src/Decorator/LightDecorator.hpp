/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** LightDecorator
*/

/**
* @file LightDecorator.hpp
* @brief File for the LightDecorator class.
*/

#ifndef LIGHTDECORATOR_HPP_
#define LIGHTDECORATOR_HPP_

#include "include.hpp"
#include "IMaterial.hpp"

/**
* @class EmissiveMaterial
* @brief Class used to decorate the light in the scene.
*/

class EmissiveMaterial : public IMaterial {
    private:
        std::shared_ptr<IMaterial> baseMaterial;
        Vec3 emitColor;
        float intensity;
    public:

        /**
        * @brief Construct a new Emissive Material object
        * @param material The material.
        * @param emitColor The color of the light.
        * @param intensity The intensity of the light.
        */
        EmissiveMaterial(std::shared_ptr<IMaterial> material, Vec3 emitColor, float intensity)
            : baseMaterial(material), emitColor(emitColor), intensity(intensity) {}

        bool scatter(const Ray& r_in, const hit_record_t& rec, Vec3& attenuation, Ray& scattered, std::shared_ptr<ILight> light, const std::vector<std::shared_ptr<IHitable>>& _obj) const override {

            if (baseMaterial->scatter(r_in, rec, attenuation, scattered, light, _obj)) {
                attenuation += emitColor * intensity;
                return true;
            } else {
                attenuation = emitColor * intensity;
                return false;
            }
        }
};

#endif /* !LIGHTDECORATOR_HPP_ */