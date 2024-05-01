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

        float x() const;
        float y() const;
        float z() const;
        float r() const;
        float g() const;
        float b() const;
        
        const Vec3& operator+() const;
        Vec3 operator-() const;
        float operator[](int i) const
		{
			return e[i];
		}
        float& operator[](int i);

        //std::istream& operator>>(std::istream &is, Vec3 &t);
        //std::ostream& Vec3::operator<<(std::ostream &os, Vec3 &t);
        
        Vec3& operator+=(const Vec3 &v2);
		Vec3& operator+(const Vec3 &v1, const Vec3 &v2);
        Vec3& operator-=(const Vec3 &v2);
        Vec3& operator*=(const Vec3 &v2);
        Vec3& operator/=(const Vec3 &v2);
        Vec3& operator*=(const float t);
        Vec3& operator/=(const double t);
        
        float length() const
		{
			return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
		}
        float length_squared() const;
        void make_unit_vector();
        
        float e[3];
    private:
};

#endif /* !Vec3_HPP_ */
