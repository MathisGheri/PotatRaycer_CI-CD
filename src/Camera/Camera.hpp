/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Camera
*/

/**
* @file Camera.hpp
* @brief Header file for the Camera class. 
*/

#pragma once

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Vec3.hpp"
#include "Ray.hpp"
#include "SingletonLogger.hpp"

/**
* @class Camera
* @brief Class for creating a camera object in the scene.
* 	
* @details The Camera class provides a way to create a camera object in the scene.
* It allows for the creation of a camera with a specified lookfrom, lookat, vup, vfov, aspect, aperture, and focus_dist.
*/

class Camera {
	public:
		Camera() = default;

		/**
        * @brief Camera constructor.
        * @param lookfrom The position of the camera.
		* @param lookat The point the camera is looking at.
		* @param vup The up vector of the camera.
		* @param vfov The field of view of the camera.
		* @param aspect The aspect ratio of the camera.
		* @param aperture The aperture of the camera.
		* @param focus_dist The focus distance of the camera. 
        */
		Camera(Vec3 lookfrom, Vec3 lookat, Vec3 vup, float vfov, float aspect, float aperture, float focus_dist);
		~Camera();

		/**
		* @brief Get the Ray object.
		* @return The Ray object.
		*/
		Ray get_Ray(float s, float t);
		Vec3 lower_left_corner, horizontal, vertical, origin;
		float lens_radius;
	private:
		Vec3 u;
		Vec3 v;
		Vec3 w;
};

#endif /* !CAMERA_HPP_ */
