/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Core
*/
#pragma once

#ifndef CORE_HPP_
#define CORE_HPP_

#include "include.hpp"
#include "Scene.hpp"

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
