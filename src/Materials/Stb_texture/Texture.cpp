/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Texture.cpp
*/

#include "Texture.hpp"

Vec3 Texture::sample(float u, float v) const {
    if (!data) return Vec3(0, 0, 0);  // Return black if texture failed to load

    // Assurez-vous que les coordonnées UV sont dans l'intervalle [0, 1]
    u = fmod(u, 1.0f);
    v = fmod(v, 1.0f);
    if (u < 0) u += 1.0f;
    if (v < 0) v += 1.0f;

    // Mapper les coordonnées UV aux indices de pixel
    int x = static_cast<int>(u * width);
    int y = static_cast<int>((1.0f - v) * height);  // Invert v to match the image's coordinate system
    x = std::min(x, width - 1);
    y = std::min(y, height - 1);

    int pixelIndex = (y * width + x) * channels;

    // Échantillonner la couleur en fonction du nombre de canaux
    if (channels == 3 || channels == 4) { // Assuming RGB or RGBA
        return Vec3::fromRGB(data[pixelIndex], data[pixelIndex + 1], data[pixelIndex + 2]);
    } else if (channels == 1) { // Assuming grayscale
        return Vec3::fromRGB(data[pixelIndex], data[pixelIndex], data[pixelIndex]);
    } else {
        return Vec3(1, 0, 1); // Return magenta for unsupported channel count
    }
}

bool Texture::scatter(const Ray &r_in, const hit_record_t &rec, Vec3 &attenuation, Ray &scattered, Light light, const std::vector<std::shared_ptr<IHitable>> &_obj) const
{
    Vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = Ray(rec.p, reflected + 0 * random_in_unit_sphere());
    Vec3 textureColor = this->sample(rec.uv.e[0], rec.uv.e[1]);
    attenuation = textureColor;
    return (dot(scattered.direction(), rec.normal) > 0);
}
