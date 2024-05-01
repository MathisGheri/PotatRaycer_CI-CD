/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Lambertian
*/

#include "../IMaterial.hpp"

#ifndef LAMBERTIAN_HPP_
#define LAMBERTIAN_HPP_

class Lambertian : public IMaterial {
    public:
        Lambertian(const Vec3& a);
        ~Lambertian();
        bool scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered) const override final;
    private:
        Vec3 albedo;
};

#endif /* !LAMBERTIAN_HPP_ */
