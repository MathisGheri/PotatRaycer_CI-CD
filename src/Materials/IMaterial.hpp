/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IMaterial
*/

/**
* @file IMaterial.hpp
* @brief File for the IMaterial class.
*/

#pragma once

#ifndef IMATERIAL_HPP_
#define IMATERIAL_HPP_

#include "Vec3.hpp"
#include "Ray.hpp"
#include "struct.h"
#include "ILight.hpp"
#include "IHitable.hpp"

struct hit_record_s;

/**
* @class IMaterial
* @brief Class used to create the Material. 
*/

class IMaterial {
    public:
        virtual ~IMaterial() = default;

        /**
        * @brief Function to scatter the ray.
        * @param r_in The ray.
        * @param rec The hit record.
        * @param attenuation The attenuation.
        * @param scattered The scattered ray.
        * @param light The light.
        * @param _obj The objects in the scene.
        * @return True if the ray has been scattered, false otherwise.
        */
        virtual bool scatter(const Ray &r_in, const hit_record_t &rec, Vec3 &attenuation, Ray &scattered, std::shared_ptr<ILight> light, const std::vector<std::shared_ptr<IHitable>> &_obj) const = 0;    
    
        /**
        * @brief Function to get the name of the material.
        * @return The name of the material.
        */
        virtual std::string getName() const = 0;
};

#endif /* !IMATERIAL_HPP_ */
