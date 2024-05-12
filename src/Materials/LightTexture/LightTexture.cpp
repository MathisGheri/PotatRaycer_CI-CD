/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** LightTexture
*/

#include "LightTexture.hpp"
#include "SingletonLogger.hpp"

LightTexture::LightTexture(float a)
{
    albedo = Vec3(a, a, a);
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "LOG: LightTexture created with a = " << a << ".";
	logger->log(INFO, msg.str());
}

LightTexture::~LightTexture()
{
}
//rajouter light + objs

bool LightTexture::hit(const Ray& r, float t_min, float t_max, hit_record_t& rec, const std::vector<std::shared_ptr<IHitable>>& _world) const {
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

bool LightTexture::scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, Light light, const std::vector<std::shared_ptr<IHitable>>& _obj) const
{
    scattered = Ray(rec.p, rec.normal);
    attenuation = albedo;
    return true;
}

std::string LightTexture::getName() const
{
    return "LightTexture";
}
