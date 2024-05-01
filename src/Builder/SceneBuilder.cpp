/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** SceneBuilder
*/

#include "SceneBuilder.hpp"

SceneBuilder::SceneBuilder()
{
    if (scene != nullptr)
            delete scene;
    scene = new Scene();
}

SceneBuilder::~SceneBuilder()
{
    //delete(this->scene);
    //delete light/camera etc
}

void SceneBuilder::createCamera(std::map<std::string,std::tuple<float,float,float>> camParams)
{
    try {
        Vec3 lookfrom(std::get<0>(camParams["lookfrom"]), std::get<1>(cameraParams["lookfrom"]), std::get<2>(cameraParams["lookfrom"]));
        Vec3 lookat(std::get<0>(camParams["lookat"]), std::get<1>(cameraParams["lookat"]), std::get<2>(cameraParams["lookat"]));
        Vec3 vup(std::get<0>(camParams["vup"]), std::get<1>(cameraParams["vup"]), std::get<2>(cameraParams["vup"]));
        float vfov = std::get<0>(camParams["vfov"]);
        float aspect = std::get<0>(camParams["aspect"]);
        float aperture = std::get<0>(camParams["aperture"]);
        float focus_dist = std::get<0>(camParams["focus_dist"]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        exit(84);
    }
    std::unique_ptr<Camera> camera = std::make_unique<Camera>(lookfrom, lookat, vup, vfov, aspect, aperture, focus_dist);
    scene->setCamera(std::move(camera));
    //delete camera ?
}

void SceneBuilder::createLight(std::map<std::string,std::tuple<float,float,float>>)
{
    try {
        Vec3 pos(std::get<0>(lightParams.at("position")), std::get<1>(lightParams.at("position")), std::get<2>(lightParams.at("position")));
        float intensity = std::get<0>(lightParams.at("intensity"));
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        exit(84);
    }
    Light light();
    scene->setLight(light);
    //delete light
}

void SceneBuilder::createObject(std::vector<Primitive> primitives)
{
    //créér + loop ptet faire gaffe à si on a un getSphere ou un getPlan etc..
    for (const auto& prim : primitives) {
        //rajouter des try catch partout ?
        /****Material creation****/
        std::unique_ptr<IMaterial> material;
        if (prim.material.type == "metal") {
            material = std::make_unique<Metal>(prim.material.vec, prim.material.fuzz);
        } else if (prim.material.type == "lambertian") {
            material = std::make_unique<Lambertian>(prim.material.vec);
        } else if (prim.material.type == "dielectric") {
            material = std::make_unique<Dielectric>(prim.material.ref_idx);
        }
        /****Primitive creation****/
        if (prim.type == "sphere") {
            std::unique_ptr<IHitable> object = std::make_unique<Sphere>(prim.points[0], prim.point[1].x, std::move(material));
            scene->addObject(std::move(object));
        } else if (prim.type == "plane") {
            std::unique_ptr<IHitable> object = std::make_unique<Plane>(prim.points[0], prim.points[1], material.release());
            scene->addObject(std::move(object));
        }
    }
}
//U WANT ME TO ADD SOE
Scene *SceneBuilder::getScene()
{
    return this->scene;
}
