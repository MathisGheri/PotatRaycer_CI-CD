# EPITECH PROJECT, 2024
# PotatRaycer_CI-CD
# File description:
# CMake

cmake_minimum_required(VERSION 3.14)
project(RaytracerTests)

# Set the CMake module path to include the directory where FindCriterion.cmake is located
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# Find Criterion using the custom find module
find_package(Criterion REQUIRED)

# File globbing for sources
file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Create the test executable
add_executable(run_tests ${TEST_SOURCES})
target_link_libraries(run_tests PRIVATE ${CRITERION_LIBRARIES})

# Include directories for the test target
target_include_directories(run_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../src"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Builder"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Calculus"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Camera"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Color"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Core"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Parsing"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Light"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Light/Ambiant"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Light/Directional"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Materials"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Materials/Dielectric"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Materials/Lambertian"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Materials/Metal"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Primitives"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Primitives/Sphere"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Primitives/Triangle"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Primitives/Mesh"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Primitives/Plane"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Ray"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Scene"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Vec3"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Vec2"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Observer"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Materials/Stb_texture"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Logger"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Exceptions"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Computing"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/Decorator"
)

# Option for enabling code coverage
option(ENABLE_COVERAGE "Enable code coverage reporting" ON)

if(ENABLE_COVERAGE)
    target_compile_options(run_tests PRIVATE --coverage)
    target_link_libraries(run_tests PRIVATE --coverage)
    add_custom_command(TARGET run_tests POST_BUILD
        COMMAND echo "Generating coverage report..."
        COMMAND gcovr -r ${CMAKE_CURRENT_SOURCE_DIR}/../ --html --html-details -o ${CMAKE_CURRENT_SOURCE_DIR}/coverage_report.html
        COMMENT "HTML coverage report generated in ${CMAKE_CURRENT_SOURCE_DIR}/coverage_report.html"
    )
endif()
