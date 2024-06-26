/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Texture.cpp
*/

/**
* @file Texture.cpp
* @brief File for the Texture class.
*/

#include "Texture.hpp"

Vec3 Texture::sample(float u, float v) const
{
    if (!data) return Vec3(0, 0, 0);

    u = fmod(u, 1.0f);
    v = fmod(v, 1.0f);
    if (u < 0) u += 1.0f;
    if (v < 0) v += 1.0f;

    int x = static_cast<int>(u * width);
    int y = static_cast<int>((1.0f - v) * height);
    x = std::min(x, width - 1);
    y = std::min(y, height - 1);

    int pixelIndex = (y * width + x) * channels;

    if (channels == 3 || channels == 4) {
        return Vec3::fromRGB(data[pixelIndex], data[pixelIndex + 1], data[pixelIndex + 2]);
    } else if (channels == 1) {
        return Vec3::fromRGB(data[pixelIndex], data[pixelIndex], data[pixelIndex]);
    } else {
        return Vec3(1, 0, 1);
    }
}

bool Texture::hit(const Ray& r, float t_min, float t_max, hit_record_t& rec, const std::vector<std::shared_ptr<IHitable>>& _world) const
{
    hit_record_t temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;
    for(int i = 0; i < _world.size(); i++) {
        if (_world[i]->hit(r,t_min,closest_so_far,temp_rec) && _world[i]->getMaterial()->getName() != "LightTexture") {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}

bool Texture::scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, std::shared_ptr<ILight> light, const std::vector<std::shared_ptr<IHitable>>& _obj) const
{
    Vec3 lightDir;
    lightDir = light->calculateLightDirection(rec.p);
    Vec3 shadowRayOrigin = rec.p;
    Vec3 shadowRayDirection = lightDir;
    Ray shadowRay(shadowRayOrigin, shadowRayDirection);
    hit_record_t shadowRec;

    if (hit(shadowRay, 0.001, MAXFLOAT, shadowRec, _obj)) {
        attenuation = Vec3(0, 0, 0);
        return false;
    } else {
        Vec3 textureColor = this->sample(rec.uv.e[0], rec.uv.e[1]);
        float cos_theta = fabs(dot(rec.normal, lightDir));
        attenuation = textureColor * cos_theta;
        Vec3 reflected = reflect(unit_vector(r_in.getDirection()), rec.normal);
        scattered = Ray(rec.p, reflected + random_in_unit_sphere());
        return true;
    }
}

std::string Texture::getName() const
{
    return "Texture";
}