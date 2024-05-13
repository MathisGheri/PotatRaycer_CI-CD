/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Vec3
*/

/**
* @file Vec3.hpp
* @brief Vec3 class header file.
*/

#ifndef Vec3_HPP_
#define Vec3_HPP_

#include "include.hpp"
#include "SingletonLogger.hpp"

/**
* @class Vec3
* @brief Class for representing a 3D vector.
*
* The Vec3 class provides various operations for 3-dimensional vectors, including
* initialization, scaling, addition, subtraction, normalization, and vector products.
*/
class Vec3 {
public:
    /**
     * @brief Default constructor for Vec3.
     *
     * Initializes the vector with zero values.
     */
    Vec3() : e{0.0f, 0.0f, 0.0f} {}

    /**
     * @brief Parameterized constructor for Vec3.
     * 
     * @param e0 The x-coordinate of the vector.
     * @param e1 The y-coordinate of the vector.
     * @param e2 The z-coordinate of the vector.
     */
    Vec3(float e0, float e1, float e2) {
        e[0] = e0;
        e[1] = e1;
        e[2] = e2;
    }

    /**
     * @brief Get the x-coordinate of the vector.
     * 
     * @return The x-coordinate.
     */
    inline float x() const { return e[0]; }

    /**
     * @brief Get the y-coordinate of the vector.
     * 
     * @return The y-coordinate.
     */
    inline float y() const { return e[1]; }

    /**
     * @brief Get the z-coordinate of the vector.
     * 
     * @return The z-coordinate.
     */
    inline float z() const { return e[2]; }

    /**
     * @brief Get the red component (same as x-coordinate).
     * 
     * @return The red component.
     */
    inline float r() const { return e[0]; }

    /**
     * @brief Get the green component (same as y-coordinate).
     * 
     * @return The green component.
     */
    inline float g() const { return e[1]; }

    /**
     * @brief Get the blue component (same as z-coordinate).
     * 
     * @return The blue component.
     */
    inline float b() const { return e[2]; }

    /**
     * @brief Unary plus operator.
     * 
     * @return A constant reference to the vector.
     */
    inline const Vec3& operator+() const { return *this; }

    /**
     * @brief Unary minus operator.
     * 
     * @return A new vector with negated components.
     */
    inline Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }

    /**
     * @brief Access element by index.
     * 
     * @param i Index of the element.
     * @return The element at index i.
     */
    inline float operator[](int i) const { return e[i]; }

    /**
     * @brief Access element by index.
     * 
     * @param i Index of the element.
     * @return Reference to the element at index i.
     */
    inline float& operator[](int i) { return e[i]; }

    inline Vec3& operator+=(const Vec3 &v);
    inline Vec3& operator-=(const Vec3 &v);
    inline Vec3& operator*=(const Vec3 &v);
    inline Vec3& operator/=(const Vec3 &v);
    inline Vec3& operator*=(const float t);
    inline Vec3& operator/=(const double t) { return *this *= 1/t; }

    /**
     * @brief Compute the length of the vector.
     * 
     * @return The length of the vector.
     */
    inline float length() const { return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]); }

    /**
     * @brief Compute the squared length of the vector.
     * 
     * @return The squared length of the vector.
     */
    inline float length_squared() const { return e[0]*e[0] + e[1]*e[1] + e[2]*e[2]; }

    /**
     * @brief Normalize the vector to a unit vector.
     */
    inline void make_unit_vector();

    /**
     * @brief Return a normalized version of the vector.
     * 
     * @return A new normalized vector.
     */
    inline Vec3 normalize();

    /**
     * @brief Create a Vec3 from RGB values.
     * 
     * @param r Red component (0-255).
     * @param g Green component (0-255).
     * @param b Blue component (0-255).
     * @return A Vec3 representing the color.
     */
    static Vec3 fromRGB(unsigned char r, unsigned char g, unsigned char b) {
        return Vec3(r / 255.0f, g / 255.0f, b / 255.0f);
    }

    float e[3]; ///< Array storing the x, y, and z coordinates of the vector.
};

inline std::istream& operator>>(std::istream &is, Vec3 &t) {
    is >> t.e[0] >> t.e[1] >> t.e[2];
    return is;
}

inline std::ostream& operator<<(std::ostream &os, const Vec3 &t) {
    os << t.e[0] << " " << t.e[1] << " " << t.e[2];
    return os;
}

inline void Vec3::make_unit_vector() {
    float k = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    e[0] *= k; e[1] *= k; e[2] *= k;
}

inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline Vec3 operator*(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline Vec3 operator/(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline Vec3 operator*(float t, const Vec3 &v) {
    return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vec3 operator*(const Vec3 &v, float t) {
    return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vec3 operator/(float t, const Vec3 &v) {
    return Vec3(t / v.e[0], t / v.e[1], t / v.e[2]);
}

inline Vec3 operator/(const Vec3 &v, float t) {
    return Vec3(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}

inline float dot(const Vec3 &v1, const Vec3 &v2) {
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
                -(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0]),
                v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}

inline Vec3 Vec3::normalize() {
    float length = sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
    return Vec3(e[0] / length, e[1] / length, e[2] / length);
}

inline Vec3& Vec3::operator+=(const Vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

inline Vec3& Vec3::operator-=(const Vec3 &v) {
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}

inline Vec3& Vec3::operator*=(const Vec3 &v) {
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
}

inline Vec3& Vec3::operator/=(const Vec3 &v) {
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
}

inline Vec3& Vec3::operator*=(const float t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

/**
 * @brief Get the unit vector of a Vec3.
 * 
 * @param v The vector to normalize.
 * @return The unit vector.
 */
inline Vec3 unit_vector(Vec3 v) {
    return v / v.length();
}

/**
 * @brief Reflect a vector off a surface with a given normal.
 * 
 * @param v The incident vector.
 * @param n The normal vector of the surface.
 * @return The reflected vector.
 */
inline Vec3 reflect(const Vec3& v, const Vec3& n) {
    return v - 2 * dot(v, n) * n;
}

/**
 * @brief Refract a vector through a surface with a given normal and refraction index.
 * 
 * @param v The incident vector.
 * @param n The normal vector of the surface.
 * @param ni_over_nt The ratio of the indices of refraction.
 * @param refracted The refracted vector (output parameter).
 * @return True if refraction is possible, false otherwise.
 */
inline bool refract(const Vec3& v, const Vec3& n, float ni_over_nt, Vec3& refracted) {
    Vec3 uv = unit_vector(v);
    float dt = dot(uv, n);
    float discriminant = 1.0 - ni_over_nt * ni_over_nt * (1 - dt * dt);
    if (discriminant > 0) {
        refracted = ni_over_nt * (uv - n * dt) - n * sqrt(discriminant);
        return true;
    }
    return false;
}

/**
 * @brief Compute the Schlick approximation for reflectance.
 * 
 * @param cosine The cosine of the angle of incidence.
 * @param ref_idx The index of refraction.
 * @return The approximated reflectance.
 */
inline float schlick(float cosine, float ref_idx) {
    float r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}

/**
 * @brief Generate a random vector inside a unit sphere.
 * 
 * @return A random vector inside a unit sphere.
 */
inline Vec3 random_in_unit_sphere() {
    Vec3 p;
    do {
        p = 2.9 * Vec3(drand48(), drand48(), drand48()) - Vec3(1, 1, 1);
    } while (p.length_squared() >= 1.0);
    return p;
}

/**
 * @brief Generate a random vector inside a unit disk.
 * 
 * @return A random vector inside a unit disk.
 */
inline Vec3 random_in_unit_disk() {
    Vec3 p;
    do {
        p = 2.0 * Vec3(drand48(), drand48(), 0.0) - Vec3(1, 1, 0);
    } while (dot(p, p) >= 1.0);
    return p;
}

#endif /* !Vec3_HPP_ */
