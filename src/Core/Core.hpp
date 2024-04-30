/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Core
*/
#include <iostream>
#include "../Builder/SceneBuilder.hpp"
#include "../Scene/Scene.hpp"

#ifndef CORE_HPP_
#define CORE_HPP_

class Core {
    public:
        Core();
        ~Core();
        void loadConfigFromFile(std::string filename);
        void assembleScene(/*tableau de la config*/);
        void generatePPM();
        Scene *getScene();
    private:
        Scene *scene;
};

#endif /* !CORE_HPP_ */
