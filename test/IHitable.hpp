/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IHitable
*/
#pragma once

#ifndef IHITABLE_HPP_
#define IHITABLE_HPP_

#include "Ray.hpp"
#include "Vec3.hpp"
#include "struct.h"

class IHitable {
    public:
    	virtual bool hit(const Ray &r, float t_min, float t_max, hit_record_t &rec) const = 0;
};

#endif /* !IHITABLE_HPP_ */
