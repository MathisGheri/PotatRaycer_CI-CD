/*
** EPITECH PROJECT, 2023
** PotatRaycer_CI-CD
** File description:
** Mesh.hpp
*/

#pragma once

#ifndef MESH_HPP_
#define MESH_HPP_

#include "IHitable.hpp"
#include "IMaterial.hpp"
#include "Triangle.hpp"

class Mesh : public IHitable {
    std::vector<Triangle> triangles;
public:
    Mesh() = default;
    Mesh(const std::vector<Triangle>& tris);
    const std::vector<Triangle> &getTriangles()
    {
        return triangles;
    }
    virtual bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const override;
};

#endif /* !MESH_HPP_ */