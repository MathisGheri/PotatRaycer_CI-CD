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
//rajouter light + objs
bool Lambertian::scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, Light light, const std::vector<std::shared_ptr<IHitable>>& _obj) const
{
    Vec3 lightDir = light.calculateLightDirection(rec.p);
    float cos_theta = fabs(dot(rec.normal, lightDir));

    Vec3 shadowRayOrigin = rec.p;
    Vec3 shadowRayDirection = light.getPosition() - rec.p;
    Ray shadowRay(shadowRayOrigin, shadowRayDirection);
    hit_record_t shadowRec;

    for (const auto& obj : _obj) {
        if (obj->hit(shadowRay, 0.001, MAXFLOAT, shadowRec)) {
            float distanceToLight = (light.getPosition() - rec.p).length();
            float attenuationFactor = 1 / (1 + distanceToLight);
            attenuation = albedo * light.getIntensity() * cos_theta * attenuationFactor;
            return false;
        }
    }

    scattered = Ray(rec.p, rec.normal + random_in_unit_sphere());
    attenuation = albedo * light.getIntensity() * cos_theta;
    return true;
}
