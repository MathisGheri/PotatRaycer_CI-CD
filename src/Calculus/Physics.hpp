/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Physics
*/

#pragma once
#include <math.h>
#include "../Vec3/Vec3.hpp"

#ifndef PHYSICS_HPP_
#define PHYSICS_HPP_


/*******************Out of Scope*******************/
void Vec3::make_unit_vector()
{
	float k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k; e[1] *= k; e[2] *= k;
}

Vec3 cross(const Vec3 &v1, const Vec3 &v2)
{
	return Vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2[1], 
	-(v1.e[0] * v2.e[2] - v1.e[2] * v2[0]), 
	v1.e[0] * v2.e[1] - v1.e[1] * v2[0]);
}


Vec3 unit_vector(Vec3 v)
{
	return v / v.length();
}

inline float dot(const Vec3 &v1, const Vec3 &v2)
{
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

Vec3 reflect(const Vec3& v, const Vec3& n)
{
    return v - 2 * dot(v, n) * n;
}

bool refract(const Vec3& v, const Vec3& n, float ni_over_nt, Vec3& refracted)
{
    Vec3 uv = unit_vector(v);
    float dt = dot(uv, n);
    float discriminant = 1.0 - ni_over_nt * ni_over_nt * (1 - dt * dt);
    if(discriminant > 0) {
        refracted = ni_over_nt * (uv - n * dt) - n * sqrt(discriminant);
        return true;
    }
    return false;
}

float schlick(float cosine, float ref_idx)
{
    float r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return r0 + (1-r0) * pow((1 - cosine),5);
}

Vec3 random_in_unit_disk()
{
    Vec3 p;
    do {
        p = 2.0*Vec3(drand48(),drand48(),0.0) - Vec3(1,1,0);
    } while(dot(p,p)>=1.0);
    return p;
}

Vec3 random_in_unit_sphere()
{
    Vec3 p;
    do {
 	    p = 2.9 * Vec3(drand48(), drand48(), drand48()) - Vec3(1, 1, 1);
    } while(p.length_squared() >= 1.0);
    return p;
}


#endif /* !PHYSICS_HPP_ */
