// /*
// ** EPITECH PROJECT, 2024
// ** PotatRaycer_CI-CD
// ** File description:
// ** test_light
// */

// #include <criterion/criterion.h>
// #include <criterion/redirect.h>
// #include <criterion/theories.h>
// #include "Light.hpp"
// #include "Vec3.hpp"

// Test(Light, GetPosition)
// {
//     Vec3 position(1.0f, 2.0f, 3.0f);
//     Light light(position, 1.0f, Vec3(0.0f, 0.0f, 0.0f), false);
//     Vec3 result = light.getPosition();
//     cr_assert_eq(result.x(), position.x());
//     cr_assert_eq(result.y(), position.y());
//     cr_assert_eq(result.z(), position.z());
// }

// Test(Light, GetIntensity)
// {
//     Vec3 position(1.0f, 2.0f, 3.0f);
//     Light light(position, 1.0f, Vec3(0.0f, 0.0f, 0.0f), false);
//     float result = light.getIntensity();
//     cr_assert_eq(result, 1.0f);
// }

// Test(Light, CalculateLightDirBlop)
// {
//     Vec3 position(1.0f, 2.0f, 3.0f);
//     Light light(position, 1.0f, Vec3(0.0f, 0.0f, 0.0f), false);
//     Vec3 point(2.0f, 3.0f, 4.0f);
//     Vec3 result_blop = light.calculateLightDirection(point);
//     double epsilon = 0.0001;
//     cr_assert_float_eq(result_blop.x(), -0.577350f, epsilon);
//     cr_assert_float_eq(result_blop.y(), -0.577350f, epsilon);
//     cr_assert_float_eq(result_blop.z(), -0.577350f, epsilon);
// }

// Test(Light, return_normal)
// {
//     Vec3 position(1.0f, 2.0f, 3.0f);
//     Light light(position, 1.0f, Vec3(0.0f, 0.0f, 0.0f), false);
//     Vec3 result = light.getNormal();
//     cr_assert_eq(result.x(), 0.0f);
//     cr_assert_eq(result.y(), 0.0f);
//     cr_assert_eq(result.z(), 0.0f);
// }

// Test(Light, return_direc)
// {
//     Vec3 position(1.0f, 2.0f, 3.0f);
//     Light light(position, 1.0f, Vec3(0.0f, 0.0f, 0.0f), false);
//     bool result = light.isDirec();
//     cr_assert_eq(result, false);
// }

// Test(Light, return_direc_true)
// {
//     Vec3 position(1.0f, 2.0f, 3.0f);
//     Light light(position, 1.0f, Vec3(0.0f, 0.0f, 0.0f), true);
//     bool result = light.isDirec();
//     cr_assert_eq(result, true);
// }

// Test(Light, return_direc_false)
// {
//     Vec3 position(1.0f, 2.0f, 3.0f);
//     Light light(position, 1.0f, Vec3(0.0f, 0.0f, 0.0f), false);
//     bool result = light.isDirec();
//     cr_assert_eq(result, false);
// }
