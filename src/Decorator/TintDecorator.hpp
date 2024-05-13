/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** TintDecorator
*/

#pragma once

#ifndef TINTDECORATOR_HPP_
#define TINTDECORATOR_HPP_

#include "include.hpp"
#include "IMaterial.hpp"

class TintedMaterial : public IMaterial {
    public:
        TintedMaterial(std::shared_ptr<IMaterial> material, Vec3 tint) : baseMaterial(material), tint(tint) {}

        bool scatter(const Ray& r_in, const hit_record_t& rec, Vec3& attenuation, Ray& scattered, Light light, const std::vector<std::shared_ptr<IHitable>>& _obj) const override {
            if (baseMaterial->scatter(r_in, rec, attenuation, scattered, light, _obj)) {
                attenuation *= tint;
                return true;
            }
            return false;
        }
        std::string getName() const override final { return "Tinted"; };
    private:
        std::shared_ptr<IMaterial> baseMaterial;
        Vec3 tint;
};

#endif /* !TINTDECORATOR_HPP_ */