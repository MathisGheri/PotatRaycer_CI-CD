/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Metal
*/

#include "Metal.hpp"

Metal::Metal(const Vec3& a, const float f) : albedo(a)
{
    if (f < 1)
        fuzz = f;
    else
        fuzz = 1;
    
    std::cout << "LOG: Camera created with these parameters: a = " << a << ", f = " << f << "." << std::endl;

}

Metal::~Metal()
{
}

bool Metal::scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered) const
{
    Vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = Ray(rec.p, reflected + fuzz * random_in_unit_sphere());
    attenuation = albedo;
    return (dot(scattered.direction(), rec.normal) > 0);
}