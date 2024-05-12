/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Plane
*/
#pragma once

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include "IHitable.hpp"
#include "include.hpp"
#include "struct.h"

class Plane : public IHitable{
    public:
        Plane(Vec3 p, Vec3 n);
        ~Plane();
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t &rec) const override final;
        void setMaterial(std::shared_ptr<IMaterial> m);
        std::shared_ptr<IMaterial> getMaterial();
    private:
        Vec3 point;
        Vec3 normal;
        std::shared_ptr<IMaterial> mat_ptr;
};

#endif //PLANE_HPP_