/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Sphere
*/
#pragma once

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "include.hpp"
#include "IHitable.hpp"
#include "IMaterial.hpp"

class Sphere : public IHitable {
    public:
        Sphere(Vec3 cen, float r);
        ~Sphere();
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const;
        void setMaterial(std::shared_ptr<IMaterial> m);
        std::shared_ptr<IMaterial> getMaterial();
    private:
        Vec3 center;
        float radius;
        std::shared_ptr<IMaterial> mat_ptr;
};

#endif /* !SPHERE_HPP_ */
