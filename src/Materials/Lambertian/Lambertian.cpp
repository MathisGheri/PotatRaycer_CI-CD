/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Lambertian
*/

/**
* @file Lambertian.cpp
* @brief File for the Lambertian class.
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

bool Lambertian::hit(const Ray& r, float t_min, float t_max, hit_record_t& rec, const std::vector<std::shared_ptr<IHitable>>& _world) const {
    hit_record_t temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;
    for(int i = 0; i < _world.size(); i++) {
        if (_world[i]->hit(r,t_min,closest_so_far,temp_rec) && _world[i]->getMaterial()->getName() != "LightTexture") {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}

bool Lambertian::scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, std::shared_ptr<ILight> light, const std::vector<std::shared_ptr<IHitable>>& _obj) const
{
    if (!(light->getType() == "directional")) {
        Vec3 lightDir = light->calculateLightDirection(rec.p);
        float cos_theta = fabs(dot(rec.normal, lightDir));
        Vec3 shadowRayOrigin = rec.p;
        Vec3 shadowRayDirection = light->getPosition() - rec.p;
        Ray shadowRay(shadowRayOrigin, shadowRayDirection);
        hit_record_t shadowRec;
        if (hit(shadowRay, 0.001, MAXFLOAT, shadowRec, _obj)) {
            float distanceToLight = (light->getPosition() - rec.p).length();
            float attenuationFactor = 1 / (1 + distanceToLight);
            attenuation = albedo * light->getIntensity() * cos_theta * attenuationFactor;
            return false;
        }
        scattered = Ray(rec.p, rec.normal + random_in_unit_sphere());
        attenuation = albedo * light->getIntensity() * cos_theta;
        return true;
    } else {
        Vec3 lightDir = light->getNormal();
        lightDir.make_unit_vector();
        Vec3 lightPos = light->getPosition();
        float cos_theta = dot(rec.normal, lightDir);
        Vec3 pointToLight = lightPos - rec.p;
        if (dot(pointToLight, light->getNormal()) > 0 && cos_theta > 0) {
            Vec3 shadowRayOrigin = rec.p;
            Vec3 shadowRayDirection = lightDir;
            Ray shadowRay(shadowRayOrigin, shadowRayDirection);
            hit_record_t shadowRec;
            if (hit(shadowRay, 0.001, MAXFLOAT, shadowRec, _obj)) {
                attenuation = Vec3(0, 0, 0);
                return false;
            }
            else {
                float lightsize = light->getSize();
                if (lightsize > 0.0) {
                    Vec3 lightOriginToHit = rec.p - lightPos;
                    Vec3 lightNormal = light->getNormal();
                    Vec3 projectedHitToLight = lightOriginToHit - dot(lightOriginToHit, lightNormal) * lightNormal;
                    float projectedDistanceToLight = projectedHitToLight.length();
                    if (projectedDistanceToLight < lightsize) {
                        scattered = Ray(rec.p, rec.normal + random_in_unit_sphere());
                        attenuation = albedo * light->getIntensity() * cos_theta;
                        return true;
                    } else {
                        attenuation = Vec3(0, 0, 0);
                        return false;
                    }
                } else {
                    scattered = Ray(rec.p, rec.normal + random_in_unit_sphere());
                    attenuation = albedo * light->getIntensity() * cos_theta;
                    return true;
                }

            }
        }
        else {
            attenuation = Vec3(0, 0, 0);
            return false;
        }
    }
}

std::string Lambertian::getName() const
{
    return "Lambertian";
}