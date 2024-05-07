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

bool Lambertian::hit(const Ray& r, float t_min, float t_max, hit_record_t& rec, const std::vector<std::shared_ptr<IHitable>>& _world) const {
    hit_record_t temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;
    for(int i = 0; i < _world.size(); i++) {
        if (_world[i]->hit(r,t_min,closest_so_far,temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}

bool Lambertian::scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, Light light, const std::vector<std::shared_ptr<IHitable>>& _obj) const
{
    Vec3 lightDir = light.calculateLightDirection(rec.p);
    float cos_theta = fabs(dot(rec.normal, lightDir));
    Vec3 shadowRayOrigin = rec.p; // Déplace légèrement le point pour éviter l'auto-ombrage edit: c'est deja fait
    Vec3 shadowRayDirection = light.getPosition() - rec.p;
    Ray shadowRay(shadowRayOrigin, shadowRayDirection);
    hit_record_t shadowRec;
    if (hit(shadowRay, 0.001, MAXFLOAT, shadowRec, _obj)) {
        // Le point est dans l'ombr
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
