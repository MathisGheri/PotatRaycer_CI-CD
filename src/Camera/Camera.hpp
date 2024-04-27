/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Camera
*/

#ifndef CAMERAH
#define CAMERAH

#include "Ray.h"

vec3 random_in_unit_disk() {
	vec3 p;
	do {
		p = 2.0*vec3(drand48(),drand48(),0.0) - vec3(1,1,0);
	} while(dot(p,p)>=1.0);
	return p;
}
class Camera {
public:
    // camera() {
    //     lower_left_corner = vec3(-2.0, -1.0, -1.0);
    //     horizontal = vec3(4.0, 0.0, 0.0);
    //     vertical = vec3(0.0, 2.0, 0.0);
    //     origin = vec3(0.0, 0.0, 0.0);
    // }
	Camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist);
 	ray get_ray(float s, float t);
 	vec3 lower_left_corner, horizontal, vertical, origin;
 	float lens_radius;
 	vec3 u,v,w;

};

#endif
