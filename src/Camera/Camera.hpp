/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Camera
*/
#pragma once
#include "Ray.hpp"
#include "Physics.hpp"

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

class Camera {
	public:
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

#endif /* !CAMERA_HPP_ */
