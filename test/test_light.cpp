/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** test_light
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/theories.h>
#include "Light.hpp"
#include "Vec3.hpp"

Test(Light, GetPosition)
{
    Vec3 position(1.0f, 2.0f, 3.0f);
    Light light(position, 1.0f);
    Vec3 result = light.getPosition();
    cr_assert_eq(result.x(), position.x());
    cr_assert_eq(result.y(), position.y());
    cr_assert_eq(result.z(), position.z());
}

Test(Light, GetIntensity)
{
    Vec3 position(1.0f, 2.0f, 3.0f);
    Light light(position, 1.0f);
    float result = light.getIntensity();
    cr_assert_eq(result, 1.0f);
}

Test(Light, CalculateLightDirBlop)
{
    Vec3 position(1.0f, 2.0f, 3.0f);
    Light light(position, 1.0f);
    Vec3 point(2.0f, 3.0f, 4.0f);
    Vec3 result_blop = light.calculateLightDirection(point);
    double epsilon = 0.0001;
    cr_assert_float_eq(result_blop.x(), -0.577350f, epsilon);
    cr_assert_float_eq(result_blop.y(), -0.577350f, epsilon);
    cr_assert_float_eq(result_blop.z(), -0.577350f, epsilon);
}