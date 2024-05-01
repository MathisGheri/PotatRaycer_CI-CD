/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IHitable
*/

#pragma once
#include "../Ray/Ray.hpp"
#include "../Materials/IMaterial.hpp"
#include "struct.h"

#ifndef IHITABLE_HPP_
#define IHITABLE_HPP_

class IHitable {
    public:
    	virtual bool hit(const Ray &r, float t_min, float t_max, hit_record_t &rec) const = 0;
};

#endif /* !IHITABLE_HPP_ */
