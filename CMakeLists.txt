#
# EPITECH PROJECT, 2024
# B-OOP-400-NCE-4-1-Raytracer-mathis.gheri
# File description:
#

cmake_minimum_required(VERSION 3.14)
project(Raytracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC
   "src/*.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(Raytracer ${SRC})

# set_target_properties(Raytracer PROPERTIES
#     LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
#     PREFIX ""
# )

target_include_directories(Raytracer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Builder
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Calculus
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Camera
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Color
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Light
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)