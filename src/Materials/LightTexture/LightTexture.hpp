/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** LightTexture
*/

#ifndef LIGHTTEXTURE_HPP_
#define LIGHTTEXTURE_HPP_

#include "IMaterial.hpp"

class LightTexture : public IMaterial {
    public:
        LightTexture(float a);
        ~LightTexture();
        bool scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, Light light, const std::vector<std::shared_ptr<IHitable>> &_obj) const override final;
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec, const std::vector<std::shared_ptr<IHitable>>& _obj) const;
        std::string getName() const override final;
    private:
        Vec3 albedo;
};

#endif /* !LIGHTTEXTURE_HPP_ */
