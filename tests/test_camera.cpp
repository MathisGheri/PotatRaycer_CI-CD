/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** test_camera
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <cmath>
#include "Camera.hpp"
#include "../src/Vec3/Vec3.hpp"
#include "../src/Ray/Ray.hpp"

// Helper function to compare Vec3 with some tolerance
void assert_vec3_eq(const Vec3& vec1, const Vec3& vec2, float tol = 1e-5) {
    cr_assert_float_eq(vec1.x(), vec2.x(), tol, "X component differs");
    cr_assert_float_eq(vec1.y(), vec2.y(), tol, "Y component differs");
    cr_assert_float_eq(vec1.z(), vec2.z(), tol, "Z component differs");
}

Test(Camera, test_constructor) {
    Vec3 lookfrom(0.0f, 0.0f, 0.0f);
    Vec3 lookat(0.0f, 0.0f, -1.0f);
    Vec3 vup(0.0f, 1.0f, 0.0f);
    float vfov = 90.0f;
    float aspect = 2.0f;
    float aperture = 0.1f;
    float focus_dist = (lookfrom - lookat).length();
    Camera camera(lookfrom, lookat, vup, vfov, aspect, aperture, focus_dist);

    // Verify the camera attributes
    assert_vec3_eq(camera.origin, lookfrom);
    cr_assert_float_eq(camera.lens_radius, aperture / 2, 1e-5, "Lens radius differs");

    // Expected calculations for lower_left_corner, horizontal, and vertical
    float theta = vfov * M_PI / 180;
    float half_height = tan(theta / 2);
    float half_width = aspect * half_height;

    Vec3 expected_lower_left_corner = lookfrom - half_width * focus_dist * camera.getU() - half_height * focus_dist * camera.getV() - focus_dist * camera.getW();
    assert_vec3_eq(camera.lower_left_corner, expected_lower_left_corner);

    Vec3 expected_horizontal = 2 * half_width * camera.getU() * focus_dist;
    assert_vec3_eq(camera.horizontal, expected_horizontal);

    Vec3 expected_vertical = 2 * half_height * camera.getV() * focus_dist;
    assert_vec3_eq(camera.vertical, expected_vertical);
}

Test(Camera, test_get_Ray) {
    Vec3 lookfrom(0.0f, 0.0f, 0.0f);
    Vec3 lookat(0.0f, 0.0f, -1.0f);
    Vec3 vup(0.0f, 1.0f, 0.0f);
    float vfov = 90.0f;
    float aspect = 2.0f;
    float aperture = 0.1f;
    float focus_dist = (lookfrom - lookat).length();
    Camera camera(lookfrom, lookat, vup, vfov, aspect, aperture, focus_dist);

    float s = 0.5f;
    float t = 0.5f;
    Ray ray = camera.get_Ray(s, t);

    // Verify the ray origin and direction
    Vec3 rd = camera.lens_radius * random_in_unit_disk();
    Vec3 offset = camera.getU() * rd.x() + camera.getV() * rd.y();
    Vec3 expected_origin = camera.origin + offset;
    assert_vec3_eq(ray.getOrigin(), expected_origin);

    Vec3 expected_direction = camera.lower_left_corner + s * camera.horizontal + t * camera.vertical - camera.origin - offset;
    assert_vec3_eq(ray.getDirection(), expected_direction);
}
