/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Texture.hpp
*/

#pragma once

#ifndef Texture_HPP_
#define Texture_HPP_

#include "stb_image.h"
#include "Vec3.hpp"
#include "IMaterial.hpp"

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
    Vec3 sample(float u, float v) const;
    bool scatter(const Ray &r_in, const hit_record_t &rec, Vec3 &attenuation, Ray &scattered, Light light, const std::vector<std::shared_ptr<IHitable>> &_obj) const override;
};

#endif /* !Texture_HPP_ */
