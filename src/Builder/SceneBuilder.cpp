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
#include "Triangle.hpp"
#include "IMaterial.hpp"
#include "Metal.hpp"
#include "Lambertian.hpp"
#include "Dielectric.hpp"
#include "SingletonLogger.hpp"
#include "Mesh.hpp"
#include "Exception.hpp"
#include "TintDecorator.hpp"
#include "LightDecorator.hpp"
#include "Texture.hpp"

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
    float intensity;
    try {
        pos = Vec3(std::get<0>(lightParams.at("position")),
                    std::get<1>(lightParams.at("position")),
                    std::get<2>(lightParams.at("position")));
        intensity = std::get<0>(lightParams.at("intensity"));
    } catch (const std::exception& e) {
        throw("Light parameters not found.", Level::MIDDLE);
        exit(84);
    }
    Light light = Light(pos, intensity, Vec3(0.0, 1.0, 0.0), false, 1.0); // light update vecteur normale + bool si directionnel ou non + float pour le rayon du cercle qui sert de light dans la scene
    scene.setLight(light);
}

void SceneBuilder::createPrimitives(std::vector<Primitive> primitives)
{
    for (const auto& prim : primitives) {
        Vec3 materialVec(prim.material.vec.x, prim.material.vec.y, prim.material.vec.z);
        std::shared_ptr<IMaterial> material;

        if (prim.material.type == "metal") {
            material = std::make_shared<Metal>(materialVec, prim.material.fuzz);
        } else if (prim.material.type == "lambertian") {
            material = std::make_shared<Lambertian>(materialVec);
        } else if (prim.material.type == "dielectric") {
            material = std::make_shared<Dielectric>(prim.material.ref_idx);
        }
        if (prim.effect.type == "tint") {
            material = std::make_shared<TintedMaterial>(material, Vec3(prim.effect.color.x, prim.effect.color.y, prim.effect.color.z));
        }

        if (prim.type == "sphere") {
            Vec3 center(prim.points[0].x, prim.points[0].y, prim.points[0].z);
            float radius = prim.points[1].x;
            std::shared_ptr<IHitable> object = std::make_shared<Sphere>(center, radius);
            object->setMaterial(material);
            scene.addObject(std::move(object));
        } else if (prim.type == "plane") {
            Vec3 point1(prim.points[0].x, prim.points[0].y, prim.points[0].z);
            Vec3 point2(prim.points[1].x, prim.points[1].y, prim.points[1].z);
            std::shared_ptr<IHitable> object = std::make_shared<Plane>(point1, point2);
            object->setMaterial(material);
            scene.addObject(object);
        }
    }
}

void SceneBuilder::createMeshFromObj(std::vector<ObjectProperties> objects)
{
    for (const auto& obj : objects) {
        std::shared_ptr<IMaterial> material = std::make_shared<Texture>(obj.pathTexture);
        std::ifstream file(obj.pathFile);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << obj.pathFile << std::endl;
            return;
        }

        std::vector<Vec3> vertices;
        std::vector<std::shared_ptr<IHitable>> triangles;
        std::string line;
        std::vector<Vec2> texCoords;

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string type;
            ss >> type;
            if (type == "v") {
                float x, y, z;
                ss >> x >> y >> z;
                vertices.emplace_back(x, y, z);
            } else if (type == "vt") {
                float u, v;
                ss >> u >> v;
                texCoords.emplace_back(u, v);
            } else if (type == "f") {
                std::string vertexInfo;
                std::vector<int> vertexIndices;
                std::vector<int> textureIndices;

                while (ss >> vertexInfo) {
                    size_t pos1 = vertexInfo.find('/');
                    size_t pos2 = vertexInfo.find('/', pos1 + 1);

                    int vertexIndex = std::stoi(vertexInfo.substr(0, pos1)) - 1;
                    vertexIndices.push_back(vertexIndex);

                    if (pos1 != std::string::npos && pos1 + 1 != pos2) {
                        int textureIndex = std::stoi(vertexInfo.substr(pos1 + 1, pos2 - pos1 - 1)) - 1;
                        textureIndices.push_back(textureIndex);
                    }
                }
                if (vertexIndices.size() >= 3) {
                    for (int i = 0; i < vertexIndices.size() - 2; i++) {
                        triangles.push_back(std::make_unique<Triangle>(
                            vertices[vertexIndices[0]], vertices[vertexIndices[i + 1]], vertices[vertexIndices[i + 2]],
                            texCoords[textureIndices[0]], texCoords[textureIndices[i + 1]], texCoords[textureIndices[i + 2]]));
                        triangles.back()->setMaterial(material);
                    }
                }
            }
        }

        Vec3 position(obj.position.x, obj.position.y, obj.position.z);
        Vec3 rotation(obj.rotation.x, obj.rotation.y, obj.rotation.z);
        Vec3 scale(obj.scale.x, obj.scale.y, obj.scale.z);

        file.close();
        Mesh mesh(triangles, position, rotation, scale);
        mesh.transformVertices();
        std::shared_ptr<IHitable> meshPtr = std::make_shared<Mesh>(mesh);
        scene.addObject(std::move(meshPtr));
    }
}

const Scene &SceneBuilder::getScene() const
{
    return this->scene;
}
