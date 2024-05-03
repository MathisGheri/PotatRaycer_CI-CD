/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** SceneBuilder
*/

/**
* @file SceneBuilder.cpp
* @brief Implementation of the builder class to create scenes. 
*/

#include "SceneBuilder.hpp"
#include "Vec3.hpp"
#include "Light.hpp"
#include "Camera.hpp"
#include "IHitable.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "IMaterial.hpp"
#include "Metal.hpp"
#include "Lambertian.hpp"
#include "Dielectric.hpp"
#include "SingletonLogger.hpp"
#include "Exception.hpp"

SceneBuilder::SceneBuilder()
{
    if (scene != nullptr)
        delete(scene);
    scene = new Scene();
    Logger* logger = LoggerSingleton::getInstance();
    logger->log(INFO, "SceneBuilder created.");
}

SceneBuilder::~SceneBuilder() {}

void SceneBuilder::createCamera(std::map<std::string,std::tuple<float,float,float>> camParams)
{
    Vec3 lookfrom;
    Vec3 lookat;
    Vec3 vup;
    float vfov;
    float aspect;
    float aperture;
    float focus_dist;

    try {
        lookfrom = Vec3(std::get<0>(camParams["lookfrom"]), std::get<1>(camParams["lookfrom"]), std::get<2>(camParams["lookfrom"]));
        lookat = Vec3(std::get<0>(camParams["lookat"]), std::get<1>(camParams["lookat"]), std::get<2>(camParams["lookat"]));
        vup = Vec3(std::get<0>(camParams["vup"]), std::get<1>(camParams["vup"]), std::get<2>(camParams["vup"]));
        vfov = std::get<0>(camParams["vfov"]);
        aspect = std::get<0>(camParams["aspect"]);
        aperture = std::get<0>(camParams["aperture"]);
        focus_dist = std::get<0>(camParams["focus_dist"]);
    } catch (const std::exception &e) {
        throw("Camera parameters not found.", Level::MIDDLE);
        exit(84);
    }

    std::unique_ptr<Camera> camera = std::make_unique<Camera>(lookfrom, lookat, vup, vfov, aspect, aperture, focus_dist);
    scene->setCamera(std::move(camera));
}

void SceneBuilder::createLight(std::map<std::string, std::tuple<float, float, float>> lightParams)
{
    Vec3 pos;
    float intensity; //modifier ce try catch
    try {
        pos = Vec3(std::get<0>(lightParams.at("position")),
                   std::get<1>(lightParams.at("position")),
                   std::get<2>(lightParams.at("position")));
        intensity = std::get<0>(lightParams.at("intensity"));
    } catch (const std::exception& e) {
        throw("Light parameters not found.", Level::MIDDLE);
        exit(84);
    }
    std::unique_ptr<Light> light = std::make_unique<Light>(pos, intensity);
    scene->setLight(std::move(light));
}

void SceneBuilder::createObjects(std::vector<Primitive> primitives)
{
    for (const auto& prim : primitives) {
        /* Material creation */
        Vec3 materialVec(prim.material.vec.x, prim.material.vec.y, prim.material.vec.z);
        std::unique_ptr<IMaterial> material;
        if (prim.material.type == "metal") {
            material = std::make_unique<Metal>(materialVec, prim.material.fuzz);
        } else if (prim.material.type == "lambertian") {
            material = std::make_unique<Lambertian>(materialVec);
        } else if (prim.material.type == "dielectric") {
            material = std::make_unique<Dielectric>(prim.material.ref_idx);
        }
        /* Primitive creation */
        if (prim.type == "sphere") {
            Vec3 center(prim.points[0].x, prim.points[0].y, prim.points[0].z);
            float radius = prim.points[1].x;
            std::unique_ptr<IHitable> object = std::make_unique<Sphere>(center, radius, std::move(material));
            scene->addObject(std::move(object));
        } else if (prim.type == "plane") {
            Vec3 point1(prim.points[0].x, prim.points[0].y, prim.points[0].z);
            Vec3 point2(prim.points[1].x, prim.points[1].y, prim.points[1].z);
            std::unique_ptr<IHitable> object = std::make_unique<Plane>(point1, point2, material.release());
            scene->addObject(std::move(object));
        }
    }
}

Scene *SceneBuilder::getScene()
{
    return this->scene;
}
