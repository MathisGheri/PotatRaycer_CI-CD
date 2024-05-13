/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IHitable
*/

/**
* @file IHitable.hpp
* @brief IHitable interface header file.
*/

#pragma once

#ifndef IHITABLE_HPP_
#define IHITABLE_HPP_

#include "Ray.hpp"
#include "Vec3.hpp"
#include "Vec2.hpp"
#include "struct.h"

/**
* @class IHitable
* @brief Interface for objects that can be hit by rays.
*
* The IHitable interface defines the methods required for any object that can
* be intersected by a ray in the ray tracing system. Implementing classes must
* provide methods to handle ray intersections and manage materials.
*/
class IHitable {
    public:
        /**
         * @brief Determine if a ray hits the object.
         * 
         * This method checks if a given ray intersects with the object within
         * a specified range. If an intersection occurs, it populates the hit
         * record with details about the intersection.
         * 
         * @param r The ray to check for intersection.
         * @param t_min The minimum value of the parameter t to consider.
         * @param t_max The maximum value of the parameter t to consider.
         * @param rec The hit record to populate with intersection details.
         * @return True if the ray intersects the object, false otherwise.
         */
        virtual bool hit(const Ray &r, float t_min, float t_max, hit_record_t &rec) const = 0;

        /**
         * @brief Set the material of the object.
         * 
         * This method sets the material of the object to the provided material.
         * 
         * @param m A shared pointer to the material to set.
         */
        virtual void setMaterial(std::shared_ptr<IMaterial> m) = 0;

        /**
         * @brief Get the material of the object.
         * 
         * This method retrieves the material of the object.
         * 
         * @return A shared pointer to the material of the object.
         */
        virtual std::shared_ptr<IMaterial> getMaterial() = 0;

        /**
         * @brief Virtual destructor for IHitable.
         *
         * Ensures derived class destructors are called correctly.
         */
        virtual ~IHitable() = default;
};

#endif /* !IHITABLE_HPP_ */
