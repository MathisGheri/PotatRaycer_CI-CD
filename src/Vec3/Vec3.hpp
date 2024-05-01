/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Vec3
*/

#pragma once
#include <math.h>
#include <stdlib.h>
#include <iostream>

#ifndef Vec3_HPP_
#define Vec3_HPP_

class Vec3 {
    public:
		Vec3();
        Vec3(float e0, float e1, float e2);
        ~Vec3();

        inline float x() const;
        inline float y() const;
        inline float z() const;
        inline float r() const;
        inline float g() const;
        inline float b() const;
        
        inline const Vec3& operator+() const;
        inline Vec3 operator-() const;
        inline float operator[](int i) const;
        inline float& operator[](int i);

        //inline std::istream& operator>>(std::istream &is, Vec3 &t);
        //inline std::ostream& Vec3::operator<<(std::ostream &os, Vec3 &t);
        
        inline Vec3& operator+=(const Vec3 &v2);
        inline Vec3& operator-=(const Vec3 &v2);
        inline Vec3& operator*=(const Vec3 &v2);
        inline Vec3& operator/=(const Vec3 &v2);
        inline Vec3& operator*=(const float t);
        inline Vec3& operator/=(const double t);
        
        inline float length() const;
        inline float length_squared() const;
        inline void make_unit_vector();
        
        float e[3];
    private:
};

/*******************Out of Scope*******************/
inline std::istream& operator>>(std::istream &is, Vec3 &t)
{
 is >> t.e[0] >> t.e[1] >> t.e[2];
 return is;
}

inline std::ostream& operator<<(std::ostream &os, Vec3 &t)
{
 os << t.e[0] << " " << t.e[1] << " " << t.e[2];
 return os;
}

inline void Vec3::make_unit_vector()
{
	float k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k; e[1] *= k; e[2] *= k;
}

inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2)
{
 	return Vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2)
{
 	return Vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline Vec3 operator*(const Vec3 &v1, const Vec3 &v2)
{
 	return Vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline Vec3 operator/(const Vec3 &v1, const Vec3 &v2)
{
 	return Vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline Vec3 operator*(float t, const Vec3 &v)
{
 	return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vec3 operator*(const Vec3 &v,float t)
{
 	return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vec3 operator/(float t, const Vec3 &v)
{
 	return Vec3(t / v.e[0], t / v.e[1], t / v.e[2]);
}

inline Vec3 operator/(const Vec3 &v, float t)
{
 	return Vec3(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2)
{
	return Vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2[1], 
	-(v1.e[0] * v2.e[2] - v1.e[2] * v2[0]), 
	v1.e[0] * v2.e[1] - v1.e[1] * v2[0]);
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

inline Vec3 unit_vector(Vec3 v)
{
	return v / v.length();
}

#endif /* !Vec3_HPP_ */
