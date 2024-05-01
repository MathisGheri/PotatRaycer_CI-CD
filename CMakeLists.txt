#
# EPITECH PROJECT, 2024
# B-OOP-400-NCE-4-1-Raytracer-mathis.gheri
# File description:
#

cmake_minimum_required(VERSION 3.14)
project(raytracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC
   "src/*.cpp"
   "src/Builder/*.cpp"
   "src/Camera/*.cpp"
   "src/Color/*.cpp"
   "src/Core/*.cpp"
   "src/Light/*.cpp"
   "src/Material/Dielectric/*.cpp"
   "src/Material/Lambertian/*.cpp"
   "src/Material/Metal/*.cpp"
   "src/Parsing/*.cpp"
   "src/Primitives/Plan/*.cpp"
   "src/Primitives/Sphere/*.cpp"
   "src/Ray/*.cpp"
   "src/Scene/*.cpp"
   "src/Vec3/*.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(raytracer ${SRC})

# set_target_properties(raytracer PROPERTIES
#     LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
#     PREFIX ""
# )

target_include_directories(raytracer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Builder
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Calculus
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Camera
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Color
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Light
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Materials
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Materials/Dielectric
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Materials/Lambertian
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Materials/Lambertian
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Materials/Metal
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Parsing
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Primitives
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Primitives/Sphere
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Primitives/Plane
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ray
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Scene
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Vec3
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
