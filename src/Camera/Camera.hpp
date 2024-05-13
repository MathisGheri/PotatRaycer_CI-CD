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
		Vec3 getU() const { return u; }
		Vec3 getV() const { return v; }
		Vec3 getW() const { return w; }
	private:
		Vec3 u;
		Vec3 v;
		Vec3 w;
};

#endif /* !CAMERA_HPP_ */
