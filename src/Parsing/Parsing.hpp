/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Parsing
*/

/**
* @file Parsing.hpp
* @brief Class for parsing the configuration file.
*/

#ifndef PARSING_HPP_
#define PARSING_HPP_

#include "../include.hpp"
#include "IHitable.hpp"

/**
* @struct vec3
* @brief Structure for a 3D vector.
*/
struct vec3 {
    float x, y, z;
};

/**
* @struct Effect
* @brief Structure to store an effect.
*/
struct Effect {
    std::string type;
    vec3 color;
};

/**
* @struct Material
* @brief Structure to store a material.
*/
struct Material {
    std::string type;
    vec3 vec;
    float fuzz;
    float ref_idx;
};

/**
* @struct Primitive
* @brief Structure to store primitives.
*/
struct Primitive {
    std::string type;
    vec3 points[2];
    Material material;
    Effect effect;
};

/**
* @struct ObjectProperties
* @brief Structure to store .obj properties.
*/
struct ObjectProperties {
    std::string pathFile;
    std::string matType;
    std::string pathTexture;
    vec3 scale;
    vec3 rotation;
    vec3 position;
};

/**
* @class Parsing
* @brief Class used to parse the configuration file.
*/

class Parsing {
    public:
        Parsing(const std::string &file);
        ~Parsing() {}

        /**
        * @brief Get the camera.
        * @return The camera.
        */
        std::map<std::string, std::tuple<float, float, float>> GetCamera()
        {
            return _camera;
        }

        /**
        * @brief Get the lights.
        * @return The lights.
        */
        std::vector<Primitive> getPrimitives()
        {
            return _primitives;
        }

        /**
        * @brief Get the objects.
        * @return The objects.
        */
        std::map<std::string, std::tuple<float, float, float>> getLights()
        {
            return _light;
        }

        /**
        * @brief Get the objects.
        * @return The objects.
        */
        std::vector<ObjectProperties> getObj()
        {
            return _objects;
        }

        /**
        * @brief Parse the configuration file to fill the light map.
        * @param setting The setting to parse.
        */
        void parseLights(libconfig::Setting& setting);

        /**
        * @brief Parse the configuration file to fill the camera map.
        * @param setting The setting to parse.
        */
        void parseCamera(libconfig::Setting& setting);

        /**
        * @brief Parse the configuration file to fill the primitives vector.
        * @param setting The setting to parse.
        */
        void parsePrimitives(libconfig::Setting& setting, const std::string& type);

        /**
        * @brief Parse the configuration file to fill the objects vector.
        * @param setting The setting to parse.
        */
        void parseObj(libconfig::Setting& setting);

        /**
        * @brief Parse the configuration file to fill the logger.
        * @param setting The setting to parse.
        */
        void parseLogger(libconfig::Setting& setting);
    private:
        const std::string &_filePath;
        libconfig::Config _cfg;
        std::map<std::string, std::tuple<float, float, float>> _light;
        std::map<std::string, std::tuple<float, float, float>> _camera;
        std::vector<Primitive> _primitives;
        std::vector<ObjectProperties> _objects;
};

#endif /* !PARSING_HPP_ */
