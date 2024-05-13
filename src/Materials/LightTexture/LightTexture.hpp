/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** LightTexture
*/

/**
* @file LightTexture.hpp
* @brief File for the LightTexture class.
*/

#ifndef LIGHTTEXTURE_HPP_
#define LIGHTTEXTURE_HPP_

#include "IMaterial.hpp"

/**
* @class LightTexture
* @brief Class used to create the LightTexture.
*/

class LightTexture : public IMaterial {
    public:
        LightTexture(float a);
        ~LightTexture();
        bool scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, std::shared_ptr<ILight> light, const std::vector<std::shared_ptr<IHitable>> &_obj) const override final;    

        /**
        * @brief Function to check if the ray has hit the object.
        * @param r The ray.
        * @param t_min The minimum value of t.
        * @param t_max The maximum value of t.
        * @param rec The hit record.
        * @param _obj The objects in the scene.
        * @return True if the ray has hit the object, false otherwise.
        */
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec, const std::vector<std::shared_ptr<IHitable>>& _obj) const;
        std::string getName() const override final;
    private:
        Vec3 albedo;
};

#endif /* !LIGHTTEXTURE_HPP_ */
