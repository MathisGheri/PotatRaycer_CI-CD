/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Mesh
*/

/**
* @file Mesh.hpp
* @brief Class for handling meshes.
*/

#ifndef MESH_HPP_
#define MESH_HPP_

#include "IHitable.hpp"

/**
* @class Mesh
* @brief Class for handling meshes.
*/

class Mesh : public IHitable{
    public:
        Mesh(const std::vector<std::shared_ptr<IHitable>>& tris, const Vec3& pos, const Vec3& rot, const Vec3& scl);
        ~Mesh();
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const;
        void setMaterial(std::shared_ptr<IMaterial> m) { return ; };
        std::shared_ptr<IMaterial> getMaterial() { return nullptr; };

        /**
        * @brief Transform the triangle inside the mesh based on the values given.
        */
        void transformVertices();
    private:
        Vec3 _position; ///< Position of the mesh.
        Vec3 _rotation; ///< Rotation of the mesh.
        Vec3 _scale; ///< Scale of the mesh.
        std::vector<std::shared_ptr<IHitable>> _triangles; ///< Triangles of the mesh.
};

#endif /* !MESH_HPP_ */
