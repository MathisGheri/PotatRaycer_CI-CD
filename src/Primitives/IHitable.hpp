/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IHitable
*/

#ifndef IHITABLE_HPP_
#define IHITABLE_HPP_
#include "Ray.h"

class material;

struct hit_record {
	float t;
	vec3 p;
	vec3 normal;
	material *mat_ptr;
};

class IHitable {
    private:
    public:
    	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;

};

#endif /* !IHITABLE_HPP_ */
