/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Scene
*/

/**
* @file Scene.hpp
* @brief Scene class header file.
*/

#pragma once

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "ILight.hpp"
#include "Camera.hpp"
#include "IHitable.hpp"
#include "include.hpp"

/**
* @class Scene
* @brief Class for representing a scene in the ray tracing application.
*
* The Scene class encapsulates the components of a 3D scene, including lighting,
* camera, and objects. It provides methods to set up the scene and retrieve its
* components.
*/
class Scene {
    public:
        /**
         * @brief Default constructor for Scene.
         *
         * Initializes an empty scene with no light, camera, or objects.
         */
        Scene();

        /**
         * @brief Destructor for Scene.
         *
         * Cleans up the resources used by the scene.
         */
        ~Scene();

        /**
         * @brief Set the light for the scene.
         * 
         * @param l A shared pointer to an ILight object representing the scene's light.
         */
        void setLight(std::shared_ptr<ILight> l);

        /**
         * @brief Set the camera for the scene.
         * 
         * @param c A Camera object representing the scene's camera.
         */
        void setCamera(Camera c);

        /**
         * @brief Add an object to the scene.
         * 
         * @param obj A shared pointer to an IHitable object representing the object to be added.
         */
        void addObject(std::shared_ptr<IHitable> obj);

        /**
         * @brief Set the configuration height of the scene.
         * 
         * @param height The height of the scene configuration.
         */
        void setConfigHeight(float height);

        /**
         * @brief Set the configuration width of the scene.
         * 
         * @param width The width of the scene configuration.
         */
        void setConfigWidth(float width);

        /**
         * @brief Set the configuration Ns value of the scene.
         * 
         * @param ns The Ns value of the scene configuration.
         */
        void setConfigNs(float ns);

        /**
         * @brief Get the objects in the scene.
         * 
         * @return A constant reference to a vector of shared pointers to IHitable objects.
         */
        const std::vector<std::shared_ptr<IHitable>>& getObjects(void) const;

        /**
         * @brief Get the light in the scene.
         * 
         * @return A constant reference to a shared pointer to an ILight object.
         */
        const std::shared_ptr<ILight>& getLight(void) const;

        /**
         * @brief Get the camera in the scene.
         * 
         * @return A constant reference to a Camera object.
         */
        const Camera& getCamera(void) const;

        /**
         * @brief Get the configuration height of the scene.
         * 
         * @return A constant reference to the height value.
         */
        const float& getHeight(void) const;

        /**
         * @brief Get the configuration width of the scene.
         * 
         * @return A constant reference to the width value.
         */
        const float& getWidth(void) const;

        /**
         * @brief Get the configuration Ns value of the scene.
         * 
         * @return A constant reference to the Ns value.
         */
        const float& getNs(void) const;

    private:
        std::shared_ptr<ILight> light; ///< Shared pointer to the light in the scene.
        Camera camera; ///< The camera of the scene.
        std::vector<std::shared_ptr<IHitable>> objects; ///< Vector of shared pointers to the objects in the scene.
        float height; ///< Configuration height of the scene.
        float width; ///< Configuration width of the scene.
        float ns; ///< Configuration Ns value of the scene.
};

#endif // SCENE_HPP_
