/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Camera
*/
#pragma once

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

/**
* @file Camera.hpp
* @brief Camera class header file.
*/

#include "Vec3.hpp"
#include "Ray.hpp"
#include "SingletonLogger.hpp"

/**
* @class Camera
* @brief This class represents a camera in a scene.
* @details This class is used to create a camera in a scene.
*/

class Camera {
	public:
		/**
        * @brief Constructor for the Camera class.
        * @param lookfrom The position of the camera.
		* @param lookat The point the camera is looking at.
		* @param vup The up vector of the camera.
		* @param vfov The field of view of the camera.
		* @param aspect The aspect ratio of the camera.
		* @param aperture The aperture of the camera.
		* @param focus_dist The focus distance of the camera.
        * @note This function does not return a value but configures a new camera.
        */
		Camera(Vec3 lookfrom, Vec3 lookat, Vec3 vup, float vfov, float aspect, float aperture, float focus_dist);
		~Camera();

		/**
		* @brief Get the ray from the camera.
		* @param s The horizontal coordinate.
		* @param t The vertical coordinate.
		* @return The ray from the camera.
		*/
		Ray get_Ray(float s, float t);

		/**	
		* @param lower_left_corner The lower left corner of the camera
		* @param horizontal The horizontal vector of the camera
		* @param vertical The vertical vector of the camera
		* @param origin The origin of the camera
		* @param lens_radius The lens radius of the camera
		*/
		Vec3 lower_left_corner, horizontal, vertical, origin;
		float lens_radius;
	private:
		/**	
		* @param u The x vector of the camera
		*/	
		Vec3 u;

		/**
		* @param v The y vector of the camera 
		*/
		Vec3 v;

		/**
		* @param v The y vector of the camera 
		*/
		Vec3 w;
};

#endif /* !CAMERA_HPP_ */
