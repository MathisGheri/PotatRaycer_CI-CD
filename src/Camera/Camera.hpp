/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Camera
*/

#ifndef CAMERAH
#define CAMERAH

#pragma once
#include "Ray.hpp"

class Camera {
public:
	Camera(Vec3 lookfrom, Vec3 lookat, Vec3 vup, float vfov, float aspect, float aperture, float focus_dist);
 	Ray get_Ray(float s, float t);
 	Vec3 lower_left_corner, horizontal, vertical, origin;
 	float lens_radius;
 	Vec3 u,v,w;
};

#endif
