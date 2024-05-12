/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** SceneBuilder
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
#include "MatDecorator.hpp"
#include "TintDecorator.hpp"
#include "LightDecorator.hpp"

SceneBuilder::SceneBuilder()
{
    Scene();
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
        scene.setConfigHeight(std::get<0>(camParams["height"]));
        scene.setConfigWidth(std::get<0>(camParams["width"]));
        scene.setConfigNs(std::get<0>(camParams["ns"]));
    } catch (const std::exception &e) {
        throw("Camera parameters not found.", Level::MIDDLE);
        exit(84);
    }

    Camera camera = Camera(lookfrom, lookat, vup, vfov, aspect, aperture, focus_dist);
    scene.setCamera(camera);
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
    Light light = Light(pos, intensity, Vec3(1.0, 0.1, -0.2), true); // light update vecteur normale + bool si directionnel ou non
    scene.setLight(light);
}

void SceneBuilder::createObjects(std::vector<Primitive> primitives) {
    for (const auto& prim : primitives) {
        Vec3 materialVec(prim.material.vec.x, prim.material.vec.y, prim.material.vec.z);
        std::shared_ptr<IMaterial> material;

        // Création du matériau de base
        if (prim.material.type == "metal") {
            material = std::make_shared<Metal>(materialVec, prim.material.fuzz);
        } else if (prim.material.type == "lambertian") {
            material = std::make_shared<Lambertian>(materialVec);
            //material = std::make_shared<TintedMaterial>(material, Vec3(1.0, 0.2, 0.2));
        } else if (prim.material.type == "dielectric") {
            material = std::make_shared<Dielectric>(prim.material.ref_idx);
        }
        // Appliquer un décorateur
        //material = std::make_shared<MatDecorator>(material);
        // Création de la primitive avec le matériau décoré
        if (prim.type == "sphere") {
            auto emissiveMaterial = std::make_shared<EmissiveMaterial>(material, Vec3(1.0, 0.8, 0.2), 0.5);
            Vec3 center(prim.points[0].x, prim.points[0].y, prim.points[0].z);
            float radius = prim.points[1].x;
            std::shared_ptr<IHitable> object = std::make_shared<Sphere>(center, radius);
            object->setMaterial(emissiveMaterial);
            scene.addObject(object);
        } else if (prim.type == "plane") {
            Vec3 point1(prim.points[0].x, prim.points[0].y, prim.points[0].z);
            Vec3 point2(prim.points[1].x, prim.points[1].y, prim.points[1].z);
            std::shared_ptr<IHitable> object = std::make_shared<Plane>(point1, point2);
            object->setMaterial(material);
            scene.addObject(object);
        }
    }
}

const Scene &SceneBuilder::getScene() const
{
    return this->scene;
}
