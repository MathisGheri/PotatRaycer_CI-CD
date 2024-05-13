/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Metal
*/

/**
* @file Metal.hpp
* @brief File for the Metal class.
*/

#ifndef METAL_HPP_
#define METAL_HPP_

#include "IMaterial.hpp"

/**
* @class Metal
* @brief Class used to create a Metal.
*/

class Metal : public IMaterial {
    public:
        /**
        * @brief Construct a new Metal object
        * @param albedo The albedo of the metal.
        * @param f The fuzz of the metal.
        */
        Metal(const Vec3& albedo, const float f);
        ~Metal();
        bool scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, std::shared_ptr<ILight> light, const std::vector<std::shared_ptr<IHitable>> &_obj) const override final;
        std::string getName() const override final;
    private:
        Vec3 albedo;
        int fuzz;
};

#endif /* !METAL_HPP_ */
