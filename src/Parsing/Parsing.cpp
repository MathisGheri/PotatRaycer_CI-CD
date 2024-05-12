/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Parsing
*/

#include "Parsing.hpp"
#include "SingletonLogger.hpp"

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

    float intensity = light["intensity"]["x"];

    _light = {
        {"position", std::make_tuple(l_x, l_y, l_z)},
        {"intensity", std::make_tuple(intensity, 0, 0)}
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
