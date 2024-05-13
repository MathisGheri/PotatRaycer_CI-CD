/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Metal
*/

#ifndef METAL_HPP_
#define METAL_HPP_

#include "IMaterial.hpp"

class Metal : public IMaterial {
    public:
        Metal(const Vec3& albedo, const float f);
        ~Metal();
        bool scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, std::shared_ptr<ILight> light, const std::vector<std::shared_ptr<IHitable>> &_obj) const override final;
        std::string getName() const override final;
    private:
        Vec3 albedo;
        int fuzz;
};

#endif /* !METAL_HPP_ */
