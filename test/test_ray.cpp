/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** test_ray
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include <criterion/theories.h>
#include "Ray.hpp"
#include "Vec3.hpp"

Test(Ray, test_ray)
{
    Vec3 origin(0, 0, 0);
    Vec3 direction(1, 1, 1);
    Ray ray(origin, direction);
    Vec3 o = ray.origin();
    Vec3 d = ray.direction();
    cr_assert_eq(o, origin);
    cr_assert_eq(d, direction);
    cr_assert_eq(ray.point_at_parameter(1), Vec3(1, 1, 1));
}
