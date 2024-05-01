/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Plane
*/

#include "Plane.hpp"

Plane::Plane()
{
    
}

Plane::Plane(Vec3 p, Vec3 n, IMaterial *m) : point(p), normal(n), mat_ptr(m) {};

Plane::~Plane()
{
}

bool Plane::hit(const Ray& r, float t_min, float t_max, hit_record_t &rec) const
{
    float denom = dot(normal, r.direction());
    if (fabs(denom) > 1e-6) {
        Vec3 p0l0 = point - r.origin();
        float t = dot(p0l0, normal) / denom;
        if (t < t_max && t > t_min) {
            rec.t = t;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = normal;
            rec.mat_ptr = mat_ptr;
            return true;
        }
    }
    return false;
}