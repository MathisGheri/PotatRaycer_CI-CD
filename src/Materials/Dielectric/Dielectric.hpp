/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Dielectric
*/

#ifndef DIELECTRIC_HPP_
#define DIELECTRIC_HPP_

#include "IMaterial.hpp"

class Dielectric : public IMaterial {
    public:
        Dielectric(float ri);
        ~Dielectric();
        bool scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered) const override final;
    private:
        float ref_idx;
};

#endif /* !DIELECTRIC_HPP_ */
