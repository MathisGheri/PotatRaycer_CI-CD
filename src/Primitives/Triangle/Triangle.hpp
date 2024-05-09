/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Triangle.hpp
*/

#pragma once

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include "IHitable.hpp"
#include "IMaterial.hpp"

class Triangle : public IHitable {
    public:
        Triangle(const Vec3& a, const Vec3& b, const Vec3& c);
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const override;
    private:
        Vec3 v0, v1, v2;
};

#endif /* !TRIANGLE_HPP_ */
