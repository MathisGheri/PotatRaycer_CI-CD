/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** ILight
*/

#ifndef ILIGHT_HPP_
#define ILIGHT_HPP_

#include "Vec3.hpp"
#include "include.hpp"

class ILight {
    public:
        ILight();
        ~ILight();
        virtual std::string getType() = 0;
        virtual Vec3 getPosition() const = 0;
        virtual float getIntensity() const = 0;
        virtual Vec3 calculateLightDirection(const Vec3& point) const = 0;
        virtual Vec3 getNormal() = 0;
        virtual float getSize() = 0;
    protected:
    private:
};

#endif /* !ILIGHT_HPP_ */
