/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Lambertian
*/

#ifndef LAMBERTIAN_HPP_
#define LAMBERTIAN_HPP_

#include "IMaterial.hpp"

class Lambertian : public IMaterial {
    public:
        Lambertian(const Vec3& a);
        ~Lambertian();
        bool scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, std::shared_ptr<ILight> light, const std::vector<std::shared_ptr<IHitable>> &_obj) const override final;
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec, const std::vector<std::shared_ptr<IHitable>>& _obj) const;
        std::string getName() const override final;
    private:
        Vec3 albedo;
};

#endif /* !LAMBERTIAN_HPP_ */
