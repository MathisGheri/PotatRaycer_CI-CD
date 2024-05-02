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

struct hit_record_s;

class IMaterial {
    public:
        virtual ~IMaterial() = default;
        virtual bool scatter(const Ray &r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered) const = 0;
};

#endif /* !IMATERIAL_HPP_ */
