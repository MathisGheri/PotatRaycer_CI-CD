/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Decorator
*/

#pragma once

#ifndef DECORATOR_HPP_
#define DECORATOR_HPP_

#include "IHitable.hpp"
#include "IMaterial.hpp"

class MatDecorator : public IMaterial {
    std::shared_ptr<IMaterial> baseMaterial;

public:
    MatDecorator(std::shared_ptr<IMaterial> material) : baseMaterial(material) {}

    bool scatter(const Ray &r_in, const hit_record_t &rec, Vec3 &attenuation, Ray &scattered, Light light, const std::vector<std::shared_ptr<IHitable>> &_obj) const override {
        return baseMaterial->scatter(r_in, rec, attenuation, scattered, light, _obj);
    }
};


#endif /* !DECORATOR_HPP_ */
