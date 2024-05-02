/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** SceneBuilder
*/
#pragma once

#ifndef SCENEBUILDER_HPP_
#define SCENEBUILDER_HPP_

#include "../include.hpp"
#include "IBuilder.hpp"

class SceneBuilder : public IBuilder {
    public:
        SceneBuilder();
        ~SceneBuilder();
        void createCamera(std::map<std::string,std::tuple<float,float,float>>) override final;
        void createLight(std::map<std::string,std::tuple<float,float,float>>) override final;
        void createObjects(std::vector<Primitive>) override final;
        Scene *getScene() override final;
    private:
        Scene *scene = nullptr;
};

#endif /* !SCENEBUILDER_HPP_ */
