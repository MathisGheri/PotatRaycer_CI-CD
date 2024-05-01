/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IMaterial
*/

#pragma once
#include "../Primitives/IHitable.hpp"
#include "../Vec3/Vec3.hpp"
#include "../Ray/Ray.hpp"

#ifndef IMATERIAL_HPP_
#define IMATERIAL_HPP_

class IMaterial {
    public:
        IMaterial();
        ~IMaterial();
        virtual bool scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered) const = 0;
};

#endif /* !IMATERIAL_HPP_ */
