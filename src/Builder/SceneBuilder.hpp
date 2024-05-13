/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** SceneBuilder
*/

/** 
* @file SceneBuilder.hpp
* @brief Builder class for constructing scenes
* 
* @details The SceneBuilder class provides a concrete implementation of the IBuilder
* interface for constructing scenes. It allows for the creation of cameras,
* lights, and other objects within the scene.
*/

#pragma once

#ifndef SCENEBUILDER_HPP_
#define SCENEBUILDER_HPP_

#include "../include.hpp"
#include "IBuilder.hpp"

/**
* @class SceneBuilder
* @brief Concrete implementation of the IBuilder interface for constructing scenes.
*
* This interface declares methods for creating cameras, lights, and other
* primitive objects within a scene. It also provides a method to retrieve
* the constructed scene.
*/

class SceneBuilder : public IBuilder {
    public:
        SceneBuilder();
        ~SceneBuilder();
        void createCamera(std::map<std::string,std::tuple<float,float,float>>) override final;
        void createLight(std::map<std::string,std::tuple<float,float,float>>) override final;
        void createPrimitives(std::vector<Primitive>) override final;
        const Scene &getScene() const override final;

        /**
        * @brief Create Mesh objects in the scene.
        * @param obj A vector of ObjectProperties that contain .obj informations.
        * @note This function does not return a value but populates the scene with Mesh.
        */
        void createMeshFromObj(std::vector<ObjectProperties> obj);
    private:
        Scene scene;
};

#endif /* !SCENEBUILDER_HPP_ */
