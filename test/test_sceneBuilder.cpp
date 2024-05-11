/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** test_sceneBuilder
*/

#include <criterion/criterion.h>
#include <map>
#include <vector>
#include "SceneBuilder.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Lambertian.hpp"
#include "Metal.hpp"
#include "Dielectric.hpp"
#include "Vec3.hpp"

Test(SceneBuilder, createCamera)
{
    cr_assert_eq(1, 1);
}


