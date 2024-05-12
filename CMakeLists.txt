#
# EPITECH PROJECT, 2024
# B-OOP-400-NCE-4-1-Raytracer-mathis.gheri
# File description:
#

cmake_minimum_required(VERSION 3.14)
project(raytracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-lconfig++ -lsfml-graphics -lsfml-window -lsfml-system")

file(GLOB_RECURSE SRC
    "src/*.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(raytracer ${SRC})

target_include_directories(raytracer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Builder
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Calculus
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Camera
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Color
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Parsing
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Light
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Materials
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Materials/Dielectric
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Materials/Lambertian
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Materials/Metal
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Parsing
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Primitives
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Primitives/Sphere
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Primitives/Plane
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ray
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Scene
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Vec3
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Observer
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Logger
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Exceptions
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Computing
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

