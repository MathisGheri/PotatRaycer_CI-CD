/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** ILight
*/

#ifndef AMBIANTLIGHT_HPP_
#define AMBIANTLIGHT_HPP_

#include "ILight.hpp"

class AmbiantLight : public ILight {
    public:
        AmbiantLight(Vec3 position, float intensity);
        ~AmbiantLight();
        std::string getType() override final;
        float getIntensity() const override final;
        Vec3 getPosition() const override final;
        Vec3 calculateLightDirection(const Vec3& point) const override final;
        Vec3 getNormal() override final;
        float getSize() override final;
    private:
        std::string _type = "ambiant";
        Vec3 position;
        float intensity;
};

#endif /* !AMBIANTLIGHT_HPP_ */