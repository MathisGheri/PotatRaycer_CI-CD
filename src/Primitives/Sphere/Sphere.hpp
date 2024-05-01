/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Sphere
*/

#include <iostream>
#include "../Camera/Camera.hpp"
#include "../Light/Light.hpp"
#include "../Primitives/IHitable.hpp"
#include "../../Vec3/Vec3.hpp"
#include "../../Materials/IMaterial.hpp"

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

class Sphere : public IHitable {
    public:
        Sphere(Vec3 cen, float r, IMaterial*m);
        ~Sphere();
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const;
    private:
        Vec3 center;
        float radius;
        IMaterial *mat_ptr;
};

#endif /* !SPHERE_HPP_ */
