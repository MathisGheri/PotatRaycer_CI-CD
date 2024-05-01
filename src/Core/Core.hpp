/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Core
*/

#pragma once
#include <iostream>
#include "../Builder/SceneBuilder.hpp"
#include "../Scene/Scene.hpp"
#include "../Parsing/Parsing.hpp"

#ifndef CORE_HPP_
#define CORE_HPP_

class Core {
    public:
        Core();
        ~Core();
        void assembleScene(const std::string &filename);
        void generatePPM();
        Scene *getScene();
    private:
        Scene *scene;
};

#endif /* !CORE_HPP_ */
