/*
** EPITECH PROJECT, 2023
** PotatRaycer_CI-CD
** File description:
** Triangle.cpp
*/

#include "Triangle.hpp"
#include <cmath>

Triangle::Triangle(const Vec3 &a, const Vec3 &b, const Vec3 &c, const Vec3 &d) : v0(a), v1(b), v2(c), v3(d)
{
    computeNormal();
}

void Triangle::computeNormal()
{
    Vec3 edge1 = v1 - v0;
    Vec3 edge2 = v2 - v0;
    normal = cross(edge1, edge2);
    normal.normalize();
}

bool Triangle::hit(const Ray &r, float t_min, float t_max, hit_record_t &rec) const
{
    const float EPSILON = 0.0000001;
    Vec3 triangles[2][3] = {{v0, v1, v2}, {v0, v2, v3}};  // Deux triangles composant le quadrilatère

    for (int i = 0; i < 2; ++i) {
        Vec3 edge1 = triangles[i][1] - triangles[i][0];
        Vec3 edge2 = triangles[i][2] - triangles[i][0];
        Vec3 h = cross(r.direction(), edge2);
        float a = dot(edge1, h);
        if (a > -EPSILON && a < EPSILON) continue;  // Le rayon est parallèle à ce triangle.

        float f = 1.0 / a;
        Vec3 s = r.origin() - triangles[i][0];
        float u = f * dot(s, h);
        if (u < 0.0 || u > 1.0) continue;
        Vec3 q = cross(s, edge1);
        float v = f * dot(r.direction(), q);
        if (v < 0.0 || u + v > 1.0) continue;

        float t = f * dot(edge2, q);
        if (t > EPSILON && t < t_max && t < rec.t) { // Ray intersection
            return true;
        }
    }
    return false;  // Aucune intersection avec les deux triangles
}
