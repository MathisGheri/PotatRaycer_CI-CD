/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Texture.hpp
*/

/**
* @file Texture.hpp
* @brief File for the Texture class.
*/

#pragma once

#ifndef Texture_HPP_
#define Texture_HPP_

#include "stb_image.h"
#include "Vec3.hpp"
#include "IMaterial.hpp"

/**
* @class Texture
* @brief Class used to create a Texture.
*/
class Texture : public IMaterial {
        unsigned char* data;
        int width, height, channels;

    public:
        Texture(const std::string& filename) {
            data = stbi_load(filename.c_str(), &width, &height, &channels, 0);
            if (!data) {
                std::cerr << "Error: Could not load texture file " << filename << std::endl;
                width = height = channels = 0;
            }
        }
        ~Texture() {
            // stbi_image_free(data);
        }

        /**
        * @brief Get the color of the texture.
        * @param u The u value.
        * @param v The v value.
        * @return The color of the texture.
        */
        Vec3 sample(float u, float v) const;

        /**
        * @brief Function know if the ray hit the object
        * @param r The ray
        * @param t_min The minimum value of t
        * @param t_max The maximum value of t
        * @param rec The hit record
        * @param _world The objects in the scene
        * @return True if the ray hit the object, false otherwise
        */
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec, const std::vector<std::shared_ptr<IHitable>>& _world) const;
        bool scatter(const Ray &r_in, const hit_record_t &rec, Vec3 &attenuation, Ray &scattered, std::shared_ptr<ILight> light, const std::vector<std::shared_ptr<IHitable>> &_obj) const override;
        std::string getName() const override final;
};

#endif /* !Texture_HPP_ */
