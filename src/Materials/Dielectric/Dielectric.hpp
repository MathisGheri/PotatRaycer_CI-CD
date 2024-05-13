/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Dielectric
*/

/**
* @file Dielectric.hpp
* @brief File for the Dielectric class.
*/

#pragma once

#ifndef DIELECTRIC_HPP_
#define DIELECTRIC_HPP_

#include "IMaterial.hpp"

/**
* @class Dielectric
* @brief Class used to create the Dielectric.
*/

class Dielectric : public IMaterial {
    public:

        /**
        * @brief Construct a new Dielectric object
        * @param ri The refraction index.
        */
        Dielectric(float ri);
        ~Dielectric();
        bool scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, std::shared_ptr<ILight> light, const std::vector<std::shared_ptr<IHitable>> &_obj) const override final;
        std::string getName() const override final;
    private:
        float ref_idx;
};

#endif /* !DIELECTRIC_HPP_ */
