cmake_minimum_required(VERSION 3.14)
file(GLOB TEST_SOURCES *.cpp)
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
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Primitives/Triangle
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Primitives/Mesh
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Primitives/Plane
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ray
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Scene
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Vec3
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Vec2
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Observer
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Materials/Stb_texture
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Logger
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Exceptions
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Computing
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Decorator
)
add_executable(run_tests ${TEST_SOURCES})

target_include_directories(run_tests PRIVATE ${CRITERION_INCLUDE_DIRS})
target_link_libraries(run_tests PRIVATE ${CRITERION_LIBRARIES})

