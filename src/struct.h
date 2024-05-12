/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "Vec2.hpp"
class IMaterial;

typedef struct hit_record_s {
	float t;
	Vec3 p;
	Vec3 normal;
	std::shared_ptr<IMaterial> mat_ptr;
	Vec2 uv;
} hit_record_t;

#endif /* !STRUCT_H_ */
