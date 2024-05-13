/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Core
*/

/**
* @file Core.hpp
* @brief Core class header file.
*/

#pragma once

#ifndef CORE_HPP_
#define CORE_HPP_

#include "include.hpp"
#include "Scene.hpp"

/**
* @class Core
* @brief Class used to assemble the scene and generate the PPM file.
*/

class Core {
    public:
        Core();
        ~Core();

        /**
        * @brief Function to assemble the scene.
        * @param filename The name of the file to assemble.
        * @details This function call the parsing function to assemble the scene.
        */
        void assembleScene(const std::string &filename);

        /**
        * @brief Function to generate the PPM file.
        */ 
        void generatePPM();

        /**
        * @brief Function to get the scene.
        * @return The scene.
        */
        const Scene &getScene() const;
    private:
        Scene scene;
};

#endif /* !CORE_HPP_ */
