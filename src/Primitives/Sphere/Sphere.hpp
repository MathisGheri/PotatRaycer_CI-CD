/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Sphere
*/

/**
* @file Sphere.hpp
* @brief File for the Sphere class.
*/

#pragma once

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "include.hpp"
#include "IHitable.hpp"
#include "IMaterial.hpp"

/**
* @class Sphere
* @brief Class for handling spheres.
*/

class Sphere : public IHitable {
    public:
        Sphere(Vec3 cen, float r);
        ~Sphere();
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const;
        void setMaterial(std::shared_ptr<IMaterial> m);
        std::shared_ptr<IMaterial> getMaterial();
    private:
        Vec3 center; ///< Center of the sphere.
        float radius; ///< Radius of the sphere.
        std::shared_ptr<IMaterial> mat_ptr; ///< Pointer to the material of the intersected object.
};

#endif /* !SPHERE_HPP_ */
