/*
** EPITECH PROJECT, 2023
** PotatRaycer_CI-CD
** File description:
** Mesh.cpp
*/

#include "Mesh.hpp"

Mesh::Mesh(const std::vector<Triangle> &tris) : triangles(tris) {}

bool Mesh::hit(const Ray &r, float t_min, float t_max, hit_record_t &rec) const
{
    hit_record_t temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;

    for (const auto& triangle : triangles) {
        if (triangle.hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}