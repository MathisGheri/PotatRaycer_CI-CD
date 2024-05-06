/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IMaterial
*/

#pragma once

#ifndef IMATERIAL_HPP_
#define IMATERIAL_HPP_

#include "Vec3.hpp"
#include "Ray.hpp"
#include "struct.h"
#include "Light.hpp"
#include "IHitable.hpp"

struct hit_record_s;

class IMaterial {
    public:
        virtual ~IMaterial() = default;
        virtual bool scatter(const Ray &r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, const Light& light, std::vector<std::unique_ptr<IHitable>> world) const = 0;
};

#endif /* !IMATERIAL_HPP_ */
