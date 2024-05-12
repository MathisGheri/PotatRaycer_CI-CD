/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Mesh
*/

#include "Mesh.hpp"
#include <memory>
#include "Triangle.hpp"

Mesh::Mesh(const std::vector<std::shared_ptr<IHitable>>& tris, const Vec3& pos, const Vec3& rot, const Vec3& scl)
    : _triangles(tris), _position(pos), _rotation(rot), _scale(scl) {}

Mesh::~Mesh() {}

bool Mesh::hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const
{
    hit_record_t temp_rec;
    bool hit_anything = false;
    float closest_so_far = t_max;
    for (const auto& triangle : _triangles) {
        if (triangle->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}

void Mesh::transformVertices()
{
    for (auto& tri : _triangles) {
        std::shared_ptr<Triangle> triangle_ptr = std::dynamic_pointer_cast<Triangle>(tri);
        triangle_ptr->transform(_scale, _rotation, _position);
    }
}
