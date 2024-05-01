/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Vec3
*/

#include <math.h>
#include <stdlib.h>
#include <iostream>

#ifndef Vec3_HPP_
#define Vec3_HPP_

class Vec3 {
    public:
        Vec3(float e0, float e1, float e2);
        ~Vec3();

        inline float x() const {return e[0];}
        inline float y() const {return e[1];}
        inline float z() const {return e[2];}
        inline float r() const {return e[0];}
        inline float g() const {return e[1];}
        inline float b() const {return e[2];}
        
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

#endif /* !Vec3_HPP_ */
