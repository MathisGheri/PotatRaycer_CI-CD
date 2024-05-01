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
std::istream& operator>>(std::istream &is, Vec3 &t)
{
 is >> t.e[0] >> t.e[1] >> t.e[2];
 return is;
}

std::ostream& operator<<(std::ostream &os, Vec3 &t)
{
 os << t.e[0] << " " << t.e[1] << " " << t.e[2];
 return os;
}

void Vec3::make_unit_vector()
{
	float k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k; e[1] *= k; e[2] *= k;
}

Vec3 Vec3::operator+(const Vec3 &v1, const Vec3 &v2)
{
 	return Vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

Vec3 operator-(const Vec3 &v1, const Vec3 &v2)
{
 	return Vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

Vec3 operator*(const Vec3 &v1, const Vec3 &v2)
{
 	return Vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

Vec3 operator/(const Vec3 &v1, const Vec3 &v2)
{
 	return Vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

Vec3 operator*(float t, const Vec3 &v)
{
 	return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

Vec3 operator*(const Vec3 &v,float t)
{
 	return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

Vec3 operator/(float t, const Vec3 &v)
{
 	return Vec3(t / v.e[0], t / v.e[1], t / v.e[2]);
}

Vec3 operator/(const Vec3 &v, float t)
{
 	return Vec3(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}

Vec3 cross(const Vec3 &v1, const Vec3 &v2)
{
	return Vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2[1], 
	-(v1.e[0] * v2.e[2] - v1.e[2] * v2[0]), 
	v1.e[0] * v2.e[1] - v1.e[1] * v2[0]);
}

Vec3& Vec3::operator+=(const Vec3 &v)
{
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}

Vec3& Vec3::operator-=(const Vec3 &v)
{
	e[0] -= v.e[0];
	e[1] -= v.e[1];
	e[2] -= v.e[2];
	return *this;
}

Vec3& Vec3::operator*=(const Vec3 &v)
{
	e[0] *= v.e[0];
	e[1] *= v.e[1];
	e[2] *= v.e[2];
	return *this;
}

Vec3& Vec3::operator/=(const Vec3 &v)
{
	e[0] /= v.e[0];
	e[1] /= v.e[1];
	e[2] /= v.e[2];
	return *this;
}

Vec3& Vec3::operator*=(const float t)
{
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
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
