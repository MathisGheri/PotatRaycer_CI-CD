/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IHitable
*/

#pragma once
#include "../Ray/Ray.hpp"
#include "../Materials/IMaterial.hpp"

#ifndef IHITABLE_HPP_
#define IHITABLE_HPP_

typedef struct hit_record_s {
	float t;
	Vec3 p;
	Vec3 normal;
	IMaterial *mat_ptr;
} hit_record_t;

class IHitable {
    public:
    	virtual bool hit(const Ray &r, float t_min, float t_max, hit_record_t &rec) const = 0;
};

#endif /* !IHITABLE_HPP_ */
