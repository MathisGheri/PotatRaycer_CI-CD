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

bool Lambertian::scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, const Light& light, std::vector<std::unique_ptr<IHitable>> world) const {
    Vec3 lightDir = light.calculateLightDirection(rec.p);
    float cos_theta = fabs(dot(rec.normal, lightDir));
    // Vérifie si le point peut voir la lumière directement
    Vec3 shadowRayOrigin = rec.p; // Déplace légèrement le point pour éviter l'auto-ombrage edit: c'est deja fait
    Vec3 shadowRayDirection = light.getPosition() - rec.p;
    Ray shadowRay(shadowRayOrigin, shadowRayDirection);
    hit_record_t shadowRec;
    if (world->hit(shadowRay, 0.001, MAXFLOAT, shadowRec)) {
        // Le point est dans l'ombre
        float distanceToLight = (light.getPosition() - rec.p).length();
        float attenuationFactor = 1 / (1 + distanceToLight); // Plus le point est éloigné de la source lumineuse, plus il s'assombrit
        attenuation = albedo * light.getIntensity() * cos_theta * attenuationFactor;
        return false;
    }
    // Le point peut voir la lumière directement
    scattered = Ray(rec.p, rec.normal + random_in_unit_sphere());
    attenuation = albedo * light.getIntensity() * cos_theta;
    return true;
}