/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Parsing
*/

#ifndef PARSING_HPP_
#define PARSING_HPP_

#include "../include.hpp"

struct vec3 {
    float x, y, z;
};

struct Effect {
    std::string type;
    vec3 color;
};

struct Material {
    std::string type;
    vec3 vec;
    float fuzz;
    float ref_idx;
};

struct Primitive {
    std::string type;
    vec3 points[2];
    Material material;
    Effect effect;
};

class Parsing {
    public:
        Parsing(const std::string &file);
        ~Parsing() {}
        std::map<std::string, std::tuple<float, float, float>> GetCamera()
        {
            return _camera;
        }
        std::vector<Primitive> getPrimitives()
        {
            return _primitives;
        }
        std::map<std::string, std::tuple<float, float, float>> getLights()
        {
            return _light;
        }
        void parseLights(libconfig::Setting& setting);
        void parseCamera(libconfig::Setting& setting);
        void parsePrimitives(libconfig::Setting& setting, const std::string& type);
        
    protected:
    private:
        const std::string &_filePath;
        libconfig::Config _cfg;
        std::map<std::string, std::tuple<float, float, float>> _light;
        std::map<std::string, std::tuple<float, float, float>> _camera;
        std::vector<Primitive> _primitives;  
};

#endif /* !PARSING_HPP_ */
