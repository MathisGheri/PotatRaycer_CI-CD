/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

class IMaterial;
#include "Vec2.hpp"

typedef struct hit_record_s {
	float t;
	Vec3 p;
	Vec3 normal;
	Vec2 uv;
	IMaterial *mat_ptr;
} hit_record_t;

#endif /* !STRUCT_H_ */
