/*
** EPITECH PROJECT, 2023
** PotatRaycer_CI-CD
** File description:
** Triangle.cpp
*/

#include "Triangle.hpp"
#include <cmath>

Triangle::Triangle(const Vec3 &a, const Vec3 &b, const Vec3 &c) : v0(a), v1(b), v2(c) {}

bool Triangle::hit(const Ray &r, float t_min, float t_max, hit_record_t &rec) const
{
    const float EPSILON = 0.0000001;
    Vec3 edge1, edge2, h, s, q;
    float a, f, u, v;
    edge1 = v1 - v0;
    edge2 = v2 - v0;
    h = cross(r.direction(), edge2);
    a = dot(edge1, h);
    if (a > -EPSILON && a < EPSILON)
        return false;    // Le rayon est parallèle au triangle.

    f = 1.0 / a;
    s = r.origin() - v0;
    u = f * dot(s, h);
    if (u < 0.0 || u > 1.0)
        return false;
    q = cross(s, edge1);
    v = f * dot(r.direction(), q);
    if (v < 0.0 || u + v > 1.0)
        return false;

    // À ce stade, on sait qu'il y a une intersection, on calcule t pour savoir où
    float t = f * dot(edge2, q);
    if (t > EPSILON && t < t_max) { // Ray intersection
        rec.t = t;
        rec.p = r.point_at_parameter(t);
        rec.normal = normalize(cross(edge1, edge2));  // normale non interpolée
        return true;
    }
    return false;  // Cela signifie qu'il y a une ligne intersection mais pas un rayon intersection
}
