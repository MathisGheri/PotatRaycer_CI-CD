/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Sphere
*/

#include "Sphere.hpp"

//see what we do with material
Sphere::Sphere(Vec3 cen, float r, IMaterial *m) //fix la class material 
{
    this->center = cen;
    this->radius = r;
    this->mat_ptr = m;
}

Sphere::~Sphere()
{
    delete(this->center);
    delete(this->radius);
    delete(this->mat_ptr);
}

bool Sphere::hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const
{
	Vec3 oc = r.origin() - center;
	float a = dot(r.direction(),r.direction());
	float b = dot(oc, r.direction());
	float c = dot(oc, oc) - radius*radius;
	float discriminant = b*b - a*c;
	if(discriminant > 0) {
		float temp = (-b - sqrt(b*b-a*c))/a;
		if(temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.mat_ptr = mat_ptr;
			return true;
		}
		temp = (-b + sqrt(b*b-a*c))/a;
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

