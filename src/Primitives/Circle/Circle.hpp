/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Circle
*/

/**
* @file Circle.hpp
* @brief File for the Circle class.
*/

#pragma once

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "include.hpp"
#include "IHitable.hpp" 
#include "IMaterial.hpp"

/**
* @class Circle
* @brief Class for handling circles.
*/

class Circle : public IHitable {
    public:
        Circle(Vec3 pos, Vec3 normal, float r);
        ~Circle();
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const;
        void setMaterial(std::shared_ptr<IMaterial> m);
        std::shared_ptr<IMaterial> getMaterial();

    private:
        Vec3 position; // Position du cercle dans l'espace 3D
        Vec3 normal; // Normale du cercle
        float radius;
        std::shared_ptr<IMaterial> mat_ptr;
};

#endif /* !CIRCLE_HPP_ */
