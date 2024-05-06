/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Metal
*/

#include "Metal.hpp"
#include "SingletonLogger.hpp"

Metal::Metal(const Vec3& a, const float f) : albedo(a)
{
    if (f < 1)
        fuzz = f;
    else
        fuzz = 1;
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "LOG: Metal created with these parameters: a = " << a << ", f = " << f << ".";
	logger->log(INFO, msg.str());

}

Metal::~Metal()
{
}

bool Metal::scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, Light light, const std::vector<std::shared_ptr<IHitable>> &_obj) const
{
    Vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = Ray(rec.p, reflected + fuzz * random_in_unit_sphere());
    attenuation = albedo;
    return false;
}