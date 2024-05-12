/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Parsing
*/

#include "Parsing.hpp"
#include "SingletonLogger.hpp"
#include "FileWatcherSingleton.hpp"
#include <algorithm> 
#include "Metal.hpp"

Parsing::Parsing(const std::string &file) : _filePath(file)
{
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "LOG: Parsing created. Config file = " << file << ".";
	logger->log(INFO, msg.str());
    _cfg.readFile(_filePath.c_str());
    libconfig::Setting &root = _cfg.getRoot();
        if (root.exists("primitives") && root["primitives"].exists("planes")) {
        parsePrimitives(root["primitives"]["planes"], "plane");
    } else {
        logger->log(WARNING, "No planes found in configuration or planes section is empty.");
    }
    if (root.exists("primitives") && root["primitives"].exists("spheres")) {
        parsePrimitives(root["primitives"]["spheres"], "sphere");
    } else {
        logger->log(WARNING, "No spheres found in configuration or spheres section is empty.");
    }
    parseLights(root["light"]);
    parseCamera(root["camera"]);
    
}

/**
 * \brief Parse the primitive settings from the config file.
 *
 * Une description plus détaillée.
 *
 * \param param1 Description du premier paramètre.
 * \return Description de ce que retourne la fonction.
 */
void Parsing::parsePrimitives(libconfig::Setting& setting, const std::string& type)
{
    if (setting.getLength() == 0) {
        Logger *logger = LoggerSingleton::getInstance();
        logger->log(WARNING, "The section for " + type + " is empty.");
        return;
    }
    for (int i = 0; i < setting.getLength(); ++i) {
        Primitive p;
        p.type = type;
        libconfig::Setting &primitive = setting[i];
        if (type == "plane") {
            primitive["first"].lookupValue("x", p.points[0].x);
            primitive["first"].lookupValue("y", p.points[0].y);
            primitive["first"].lookupValue("z", p.points[0].z);
            primitive["second"].lookupValue("x", p.points[1].x);
            primitive["second"].lookupValue("y", p.points[1].y);
            primitive["second"].lookupValue("z", p.points[1].z);
        } else if (type == "sphere") {
            primitive["center"].lookupValue("x", p.points[0].x);
            primitive["center"].lookupValue("y", p.points[0].y);
            primitive["center"].lookupValue("z", p.points[0].z);
            primitive["radius"].lookupValue("x", p.points[1].x);
            primitive["radius"].lookupValue("y", p.points[1].y);
            primitive["radius"].lookupValue("z", p.points[1].z);
        }

        libconfig::Setting& mat = primitive["material"];
        mat.lookupValue("type", p.material.type);
        mat["vec"].lookupValue("x", p.material.vec.x);
        mat["vec"].lookupValue("y", p.material.vec.y);
        mat["vec"].lookupValue("z", p.material.vec.z);
        if (p.material.type == "metal")
            mat["fuzz"].lookupValue("x", p.material.fuzz);
        if (p.material.type == "dielectric")
            mat["ref_idx"].lookupValue("x", p.material.ref_idx);

        if (primitive.exists("effect")) {
            libconfig::Setting &eff = primitive["effect"];
            eff.lookupValue("type", p.effect.type);
            if (eff.exists("vec")) {
                eff["vec"].lookupValue("x", p.effect.color.x);
                eff["vec"].lookupValue("y", p.effect.color.y);
                eff["vec"].lookupValue("z", p.effect.color.z);
            }
        }
        _primitives.push_back(p);
    }
}

void Parsing::parseLights(libconfig::Setting& light)
{
    float l_x = light["position"]["x"];
    float l_y = light["position"]["y"];
    float l_z = light["position"]["z"];

    float ln_x = light["normal"]["x"];
    float ln_y = light["normal"]["y"];
    float ln_z = light["normal"]["z"];

    float intensity = light["intensity"]["x"];
    float direc = light["direc"]["x"];
    float size = light["size"]["x"];

    _light = {
        {"position", std::make_tuple(l_x, l_y, l_z)},
        {"intensity", std::make_tuple(intensity, 0, 0)},
        {"normal", std::make_tuple(ln_x, ln_y, ln_z)},
        {"direc", std::make_tuple(direc, 0, 0)},
        {"size", std::make_tuple(size, 0, 0)}
    };
}

void Parsing::parseCamera(libconfig::Setting& camera)
{
    float lf_x = camera["lookfrom"]["x"];
    float lf_y = camera["lookfrom"]["y"];
    float lf_z = camera["lookfrom"]["z"];

    float la_x = camera["lookat"]["x"];
    float la_y = camera["lookat"]["y"];
    float la_z = camera["lookat"]["z"];

    float vup_x = camera["vup"]["x"];
    float vup_y = camera["vup"]["y"];
    float vup_z = camera["vup"]["z"];

    float vfov = camera["vfov"]["x"];
    float width = camera["width"]["x"];
    float height = camera["height"]["x"];
    float aspect = width / height;
    float aperture = camera["aperture"]["x"];
    float ns = camera["ns"]["x"];

    _camera = {
        {"lookfrom", std::make_tuple(lf_x, lf_y, lf_z)},
        {"lookat", std::make_tuple(la_x, la_y, la_z)},
        {"vup", std::make_tuple(vup_x, vup_y, vup_z)},
        {"vfov", std::make_tuple(vfov, 0, 0)},
        {"aspect", std::make_tuple(aspect, 0, 0)},
        {"aperture", std::make_tuple(aperture, 0, 0)},
        {"width", std::make_tuple(width, 0, 0)},
        {"height", std::make_tuple(height, 0, 0)},
        {"ns", std::make_tuple(ns, 0, 0)}
    };
}

// bool Parsing::parseObj(const std::string& filename)
// {
//     std::vector<Vec3> vertices;
//     std::vector<Triangle> triangles;

//     std::ifstream file(filename);
//     if (!file.is_open()) {
//         std::cerr << "Cannot open file: " << filename << std::endl;
//         return false;
//     }

//     std::string line;
//     while (std::getline(file, line)) {
//         printf("line : %s\n", line.c_str());
//         std::istringstream iss(line);
//         std::string prefix;
//         iss >> prefix;
//         if (prefix == "v") {
//             Vec3 vertex;
//             iss >> vertex.e[0] >> vertex.e[1] >> vertex.e[2];
//             vertices.push_back(vertex);
//         } else if (prefix == "f") {
//             printf("f found\n");
//             std::string token;
//             int idx[4];
//             int i = 0;

//             iss >> idx[0] >> idx[1] >> idx[2] >> idx[3];

//             // while (iss >> token && i < 4) {
                
//             //     std::replace(token.begin(), token.end(), '/', ' ');
//             //     std::istringstream tokenStream(token);
//             //     int vertexIndex, texIndex, normIndex;
//             //     tokenStream >> vertexIndex >> texIndex >> normIndex;
//             //     printf("vertexIndex: %d, texIndex: %d, normIndex: %d\n", vertexIndex, texIndex, normIndex);
//             //     idx[i++] = vertexIndex;
//             // }
//             // print vertices and indices
//             printf("idx[0]: %d, idx[1]: %d, idx[2]: %d, idx[3]: %d\n", idx[0], idx[1], idx[2], idx[3]);
//             printf("vertices[0]: %f|%f|%f, vertices[1]: %f, vertices[2]: %f, vertices[3]: %f\n", vertices[idx[0] - 1].e[0], vertices[idx[0] - 1].e[1], vertices[idx[0] - 1].e[2], vertices[idx[1] - 1], vertices[idx[2] - 1], vertices[idx[3] - 1]);
//             Triangle triangle(vertices, vertices[idx[1] - 1], vertices[idx[2] - 1], vertices[idx[3] - 1]);
//             triangles.push_back(triangle);
//         }
//     }
//     Vec3 materialVec(1.0, 1.0, 1.0);
//     Vec3 pos(-1.0, 0.5, -1.0);
//     std::shared_ptr<IMaterial> material;
//     material = std::make_unique<Metal>(materialVec, 0.0);
//     _mesh = std::make_shared<Mesh>(triangles, material, pos);  // Assuming Mesh has a constructor that accepts a std::vector<Triangle>
//     return true;
// }

// bool Parsing::isObj(const std::string& filename)
// {
//     if (parseObj("Simple_Cube.obj")) {
//         return true;
//     } else {
//         std::cerr << "Failed to load OBJ model." << std::endl;
//         return false;
//     }
// }
