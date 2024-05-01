/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Metal
*/

#include "../IMaterial.hpp"
#include "../Vec3/Vec3.hpp"
#include "../Ray/Ray.hpp"

#ifndef METAL_HPP_
#define METAL_HPP_

class Metal : public IMaterial {
    public:
        Metal(const Vec3& a, float f);
        ~Metal();
        bool scatter(const Ray& r_in, const hit_record_t_t &rec, Vec3& attenuation, Ray& scattered) const override final;
    private:
        Vec3 albedo;
        int fuzz;
};

#endif /* !METAL_HPP_ */
