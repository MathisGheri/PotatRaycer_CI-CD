#
# EPITECH PROJECT, 2024
# B-OOP-400-NCE-4-1-raytracer-mathis.gheri
# File description:
#

cmake_minimum_required(VERSION 3.14)
project(raytracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC
    "src/*.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(raytracer ${SRC})

# set_target_properties(raytracer PROPERTIES
#     LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
#     PREFIX ""
# )

target_include_directories(raytracer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)