/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Sphere
*/

/**
* @file Sphere.cpp
* @brief File for the Sphere class.
*/

#include "Sphere.hpp"
#include "SingletonLogger.hpp"

Sphere::Sphere(Vec3 cen, float r) : center(cen), radius(r)
{
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "LOG: Sphere created with these params. cen = " << cen << ", r = " << r << ".";
	logger->log(INFO, msg.str());
}

Sphere::~Sphere() {}

void Sphere::setMaterial(std::shared_ptr<IMaterial> m)
{
    mat_ptr = std::move(m);
}

std::shared_ptr<IMaterial> Sphere::getMaterial()
{
    return mat_ptr;
}

bool Sphere::hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const
{
    Vec3 oc = r.getOrigin() - center;
    float a = dot(r.getDirection(), r.getDirection());
    float b = dot(oc, r.getDirection());
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b * b - a * c;

    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.mat_ptr = mat_ptr;
            return true;
        }
        temp = (-b + sqrt(b * b - a * c)) / a;
		if(temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.mat_ptr = mat_ptr;
			return true;
		}
    }
    return false;
}
