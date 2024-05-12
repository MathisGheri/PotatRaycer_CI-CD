// /*
// ** EPITECH PROJECT, 2024
// ** PotatRaycer_CI-CD
// ** File description:
// ** test_scenebuilder
// */


// #include <criterion/criterion.h>
// #include <criterion/redirect.h>
// #include <criterion/theories.h>
// #include "SceneBuilder.hpp"
// #include "Light.hpp"
// #include "Vec3.hpp"

// Test(Scene_Builder, constructor)
// {
//     SceneBuilder scene_b;
//     std::string str = "Constructor: Should create new Scene.";

//     cr_assert_not_null(scene_b.getScene(), str.c_str());
// }

// Test(Scene_Builder, createCamera)
// {
//     Vec3 pos;
//     std::string str = "No parameters were found";

//     cr_assert_not_null(pos.createCamera(), str.c_str());
// }

// Test(Scene_builder, createLight)
// {
//     Vec3 pos;
//     std::string str = "No parameters were found";

//     cr_assert_not_null(pos.createLight(), str.c_str());
// }

// Test(Scene_Builder, createObject)
// {
//     Vec3 pos;
//     std::string str = "No parms";

//     cr_assert_not_null(pos.createObjects(), str.c_str());
// }