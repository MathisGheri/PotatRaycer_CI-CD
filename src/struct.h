/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** struct
*/

#include "IMaterial.hpp"
#include "Vec3.hpp"

#ifndef STRUCT_H_
#define STRUCT_H_

class IMaterial;

typedef struct hit_record_s {
	float t;
	Vec3 p;
	Vec3 normal;
	IMaterial *mat_ptr;
} hit_record_t;

#endif /* !STRUCT_H_ */
