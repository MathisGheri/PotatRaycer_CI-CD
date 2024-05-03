/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include "SingletonLogger.hpp"

Sphere::Sphere(Vec3 cen, float r, std::unique_ptr<IMaterial> m) : center(cen), radius(r), mat_ptr(std::move(m))
{
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "LOG: Sphere created with these params. cen = " << cen << ", r = " << r << ", and material (find a way to print it).";
	logger->log(INFO, msg.str());
}

Sphere::~Sphere() {}

bool Sphere::hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const
{
    Vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = dot(oc, r.direction());
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b * b - a * c;

    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.mat_ptr = mat_ptr.get();
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.mat_ptr = mat_ptr.get();
            return true;
        }
    }
    return false;
}
