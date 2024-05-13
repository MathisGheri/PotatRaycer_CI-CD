/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IBuilder
*/

/**
* @file IBuilder.hpp
* @brief Interface for Builders used in the PotatRaycer project.
* 
* @details The IBuilder class provides the interface for building elements in the scene
* such as cameras, lights, and other objects. It allows for a flexible
* implementation of various building techniques.
*/

#ifndef IBUILDER_HPP_
#define IBUILDER_HPP_

#pragma once
#include "../include.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Parsing.hpp"

/**
* @class IBuilder
* @brief Interface for the builder pattern to construct scene components.
*
* @details This interface declares methods for creating cameras, lights, and other
* primitive objects within a scene. It also provides a method to retrieve
* the constructed scene.
*/

class IBuilder {
    public:
        virtual ~IBuilder() = default;

        /**
        * @brief Create a camera in the scene.
        * @param camParams from string identifiers to tuples representing the camera specifications.
        * @note This function does not return a value but configures the scene with a new camera.
        */
        virtual void createCamera(std::map<std::string,std::tuple<float,float,float>> camParams) = 0;

        /**
        * @brief Create a light in the scene.
        * @param lightParams Map from string identifiers to tuples representing the light specifications.
        * @note This function does not return a value but adds a light to the scene.
        */
        virtual void createLight(std::map<std::string,std::tuple<float,float,float>> lightParams) = 0;

        /**
        * @brief Create primitive objects in the scene.
        * @param primitives A vector of Primitive objects to be added to the scene.
        * @note This function does not return a value but populates the scene with primitives.
        */
        virtual void createPrimitives(std::vector<Primitive> primitives) = 0;

        /**
        * @note This function does not require any parameters since it allow user to get informations.
        * @brief Retrieve the constructed scene.
        * @return Pointer to the constructed Scene.
        */
        virtual const Scene &getScene() const = 0;
};

#endif /* !IBUILDER_HPP_ */
