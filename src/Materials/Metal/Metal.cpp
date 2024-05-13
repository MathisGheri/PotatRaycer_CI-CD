/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Metal
*/

#include "Metal.hpp"
#include "SingletonLogger.hpp"

Metal::Metal(const Vec3& albedo, const float f) : albedo(albedo)
{
    if (f < 1)
        fuzz = f;
    else
        fuzz = 1;
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "LOG: Metal created with these parameters: a = " << albedo << ", f = " << f << ".";
	logger->log(INFO, msg.str());

}

Metal::~Metal()
{
}

bool Metal::scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, Light light, const std::vector<std::shared_ptr<IHitable>> &_obj) const
{
    Vec3 reflected = reflect(unit_vector(r_in.getDirection()), rec.normal);
    scattered = Ray(rec.p, reflected + fuzz * random_in_unit_sphere());
    attenuation = albedo;
    return false;
}

std::string Metal::getName() const
{
    return "Metal";
}