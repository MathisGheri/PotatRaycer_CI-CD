/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Lambertian
*/

#include "Lambertian.hpp"
#include "SingletonLogger.hpp"

Lambertian::Lambertian(const Vec3 &a) : albedo(a)
{
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "LOG: Lambertian created with a = " << a << ".";
	logger->log(INFO, msg.str());
}

Lambertian::~Lambertian()
{
}

bool Lambertian::scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 target = rec.p + rec.normal + random_in_unit_sphere();
    scattered = Ray(rec.p, target - rec.p);
    attenuation = albedo;
    return true;
}