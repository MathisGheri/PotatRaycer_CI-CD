/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Mesh
*/

#ifndef MESH_HPP_
#define MESH_HPP_

#include "IHitable.hpp"

class Mesh : public IHitable{
    public:
        Mesh(const std::vector<std::shared_ptr<IHitable>>& tris, const Vec3& pos, const Vec3& rot, const Vec3& scl);
        ~Mesh();
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const;
        void setMaterial(std::shared_ptr<IMaterial> m) { return ; };
        std::shared_ptr<IMaterial> getMaterial() { return nullptr; };
        void transformVertices();
    private:
        Vec3 _position;
        Vec3 _rotation; // Axes de rotation avec les angles
        Vec3 _scale;
        std::vector<std::shared_ptr<IHitable>> _triangles;
};

#endif /* !MESH_HPP_ */
