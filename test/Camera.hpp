/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Camera
*/
#pragma once

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Vec3.hpp"
#include "Ray.hpp"
#include "SingletonLogger.hpp"

class Camera {
	public:
		Camera() = default;
		Camera(Vec3 lookfrom, Vec3 lookat, Vec3 vup, float vfov, float aspect, float aperture, float focus_dist);
		~Camera();
		Ray get_Ray(float s, float t);
		Vec3 lower_left_corner, horizontal, vertical, origin;
		float lens_radius;
	private:
		Vec3 u;
		Vec3 v;
		Vec3 w;
};


Camera::Camera(Vec3 lookfrom, Vec3 lookat, Vec3 vup, float vfov, float aspect, float aperture, float focus_dist)
{
	focus_dist = (lookfrom - lookat).length();
    lens_radius = aperture / 2;
 	float theta = vfov * M_PI/180;
 	float half_height = tan(theta/2);
 	float half_width = aspect * half_height;

 	origin = lookfrom;
 	w = unit_vector(lookfrom - lookat);
 	u = unit_vector(cross(vup,w));
 	v = cross(w,u);
 	lower_left_corner = origin - half_width * focus_dist * u - half_height * focus_dist * v - focus_dist * w;
	horizontal = 2*half_width * u * focus_dist;
	vertical = 2 * half_height * v * focus_dist;
	Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "Camera created with lookfrom = " << lookfrom << ", lookat = " << lookat << ", vfov = " << vfov << ", aspect = " << aspect << ", aperture = " << aperture << ", focus_dist = " << focus_dist << ".";
	logger->log(INFO, msg.str());
}

Camera::~Camera() {}

Ray Camera::get_Ray(float s, float t)
{
 	Vec3 rd = lens_radius * random_in_unit_disk();
    Vec3 offset = u * rd.x() + v * rd.y();
 	return Ray(origin + offset, lower_left_corner + s * horizontal + t * vertical - origin - offset);
}
#endif /* !CAMERA_HPP_ */
