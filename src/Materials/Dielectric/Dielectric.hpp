/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Dielectric
*/

#pragma once
#include "../IMaterial.hpp"
#include "../Vec3/Vec3.hpp"
#include "../Ray/Ray.hpp"

#ifndef DIELECTRIC_HPP_
#define DIELECTRIC_HPP_

class Dielectric : public IMaterial {
    public:
        Dielectric(float ri);
        ~Dielectric();
        bool scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered) const override final;
    private:
        float ref_idx;
};

#endif /* !DIELECTRIC_HPP_ */
