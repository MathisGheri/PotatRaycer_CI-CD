/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Vec3
*/

#include "Vec3.hpp"

Vec3::Vec3() : e{0.0f, 0.0f, 0.0f} {}

Vec3::Vec3(float e0, float e1, float e2)
{
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}

Vec3::~Vec3() {}

inline float Vec3::x() const
{
	return e[0];
}

inline float Vec3::y() const
{
	return e[1];
}

inline float Vec3::z() const
{
	return e[2];
}

inline float Vec3::r() const
{
	return e[0];
}

inline float Vec3::g() const
{
	return e[1];
}

inline float Vec3::b() const
{
	return e[2];
}

/*Operators*/
inline const Vec3& Vec3::operator+() const
{
    return *this;
}
       
inline Vec3 Vec3::operator-() const
{
    return Vec3(-e[0],-e[1],-e[2]);
}
inline float Vec3::operator[](int i) const
{
    return e[i];
}
inline float& Vec3::operator[](int i)
{
    return e[i];
}

inline Vec3& Vec3::operator+=(const Vec3 &v)
{
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}

inline Vec3& Vec3::operator-=(const Vec3 &v)
{
	e[0] -= v.e[0];
	e[1] -= v.e[1];
	e[2] -= v.e[2];
	return *this;
}

inline Vec3& Vec3::operator*=(const Vec3 &v)
{
	e[0] *= v.e[0];
	e[1] *= v.e[1];
	e[2] *= v.e[2];
	return *this;
}

inline Vec3& Vec3::operator/=(const Vec3 &v)
{
	e[0] /= v.e[0];
	e[1] /= v.e[1];
	e[2] /= v.e[2];
	return *this;
}

inline Vec3& Vec3::operator*=(const float t)
{
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}

inline Vec3& Vec3::operator/=(const double t)
{
    return *this *= 1 / t;
}

inline float Vec3::length() const
{
	return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
}

inline float Vec3::length_squared() const
{
	return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

inline void Vec3::make_unit_vector()
{
	float k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}
