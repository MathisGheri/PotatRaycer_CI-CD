/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Dielectric
*/

#include "Dielectric.hpp"
#include "SingletonLogger.hpp"

Dielectric::Dielectric(float ri) : ref_idx(ri)
{
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "LOG: Dielectric created with this parameter: ri = " << ri << ".";
	logger->log(INFO, msg.str());
}

Dielectric::~Dielectric()
{
}
bool Dielectric::scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, Light light, const std::vector<std::shared_ptr<IHitable>> &_obj) const
{
    Vec3 outward_normal;
    Vec3 reflected = reflect(r_in.getDirection(), rec.normal);
    float ni_over_nt;
    attenuation = Vec3(1.0, 1.0, 1.0);
    Vec3 refracted;
    float reflect_prob;
    float cosine;
    if (dot(r_in.getDirection(), rec.normal) > 0) {
        outward_normal = -rec.normal;
        ni_over_nt = ref_idx;
        cosine =  dot(r_in.getDirection(), rec.normal) / r_in.getDirection().length();
        cosine = sqrt(1 - ref_idx * ref_idx * (1 - cosine * cosine));
    } else {
        outward_normal = rec.normal;
        ni_over_nt = 1.0 / ref_idx;
        cosine = -dot(r_in.getDirection(), rec.normal) / r_in.getDirection().length();
    }
    if (refract(r_in.getDirection(), outward_normal, ni_over_nt, refracted))
        reflect_prob = schlick(cosine, ref_idx);
    else
        reflect_prob = 1.0;
    if (drand48() < reflect_prob)
        scattered = Ray(rec.p, reflected);
    else
        scattered = Ray(rec.p, refracted);
    return true;
}
