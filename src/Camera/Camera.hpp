/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Camera
*/

#ifndef CAMERAH
#define CAMERAH

#include "Ray.h"

Vec3 random_in_unit_disk() {
	Vec3 p;
	do {
		p = 2.0*Vec3(drand48(),drand48(),0.0) - Vec3(1,1,0);
	} while(dot(p,p)>=1.0);
	return p;
}
class Camera {
public:
    // camera() {
    //     lower_left_corner = Vec3(-2.0, -1.0, -1.0);
    //     horizontal = Vec3(4.0, 0.0, 0.0);
    //     vertical = Vec3(0.0, 2.0, 0.0);
    //     origin = Vec3(0.0, 0.0, 0.0);
    // }
	Camera(Vec3 lookfrom, Vec3 lookat, Vec3 vup, float vfov, float aspect, float aperture, float focus_dist);
 	Ray get_Ray(float s, float t);
 	Vec3 lower_left_corner, horizontal, vertical, origin;
 	float lens_radius;
 	Vec3 u,v,w;

};

#endif
