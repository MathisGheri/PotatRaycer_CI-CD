/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IMaterial
*/

#pragma once
#include "../Primitives/IHitable.hpp"
#include "Physics.hpp"
#include "../Ray/Ray.hpp"

#ifndef IMATERIAL_HPP_
#define IMATERIAL_HPP_

struct hit_record_s;

class IMaterial {
    public:
        IMaterial();
        ~IMaterial();
        virtual bool scatter(const Ray &r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered) const = 0;
};

//I have a crazy solution, wer emove all includes and we do it better ?
//like we redo this part with the struct all over again ?
//nah like we rm les #include a
//ok mais idk what will it change
//wait I need to think
//i was about to do it lol
//seems to work, don't ask how
//yes okay loll
#endif /* !IMATERIAL_HPP_ */
