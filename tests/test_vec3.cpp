/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** test_vec3
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/theories.h>
#include "Vec3.hpp"

Test(Vec3, test_vec3) {
    Vec3 vec1(1, 2, 3);
    cr_assert_eq(vec1.x(), 1);
    cr_assert_eq(vec1.y(), 2);
    cr_assert_eq(vec1.z(), 3);
}

Test(Vec3, test_vec3_addition) {
    Vec3 vec1(1, 2, 3);
    Vec3 vec2(4, 5, 6);
    Vec3 vec3 = vec1 + vec2;
    cr_assert_eq(vec3.x(), 5);
    cr_assert_eq(vec3.y(), 7);
    cr_assert_eq(vec3.z(), 9);
}

Test(Vec3, test_vec3_substraction) {
    Vec3 vec1(1, 2, 3);
    Vec3 vec2(4, 5, 6);
    Vec3 vec3 = vec1 - vec2;
    cr_assert_eq(vec3.x(), -3);
    cr_assert_eq(vec3.y(), -3);
    cr_assert_eq(vec3.z(), -3);
}

Test(Vec3, test_vec3_multiplication) {
    Vec3 vec1(1, 2, 3);
    Vec3 vec2(4, 5, 6);
    Vec3 vec3 = vec1 * vec2;
    cr_assert_eq(vec3.x(), 4);
    cr_assert_eq(vec3.y(), 10);
    cr_assert_eq(vec3.z(), 18);
}

Test(Vec3, test_vec3_division) {
    Vec3 vec1(1, 2, 3);
    Vec3 vec2(4, 5, 6);
    Vec3 vec3 = vec1 / vec2;
    double epsilon = 0.001;
    cr_assert_float_eq(vec3.x(), 0.25, epsilon);
    cr_assert_float_eq(vec3.y(), 0.4, epsilon);
    cr_assert_float_eq(vec3.z(), 0.5, epsilon);
}

Test(Vec3, test_vec3_multiplication_by_scalar) {
    Vec3 vec1(1, 2, 3);
    Vec3 vec3 = vec1 * 2;
    cr_assert_eq(vec3.x(), 2);
    cr_assert_eq(vec3.y(), 4);
    cr_assert_eq(vec3.z(), 6);
}

Test(Vec3, test_vec3_division_by_scalar) {
    Vec3 vec1(1, 2, 3);
    Vec3 vec3 = vec1 / 2;
    cr_assert_eq(vec3.x(), 0.5);
    cr_assert_eq(vec3.y(), 1);
    cr_assert_eq(vec3.z(), 1.5);
}