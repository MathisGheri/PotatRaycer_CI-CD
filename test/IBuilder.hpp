/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IBuilder
*/

#ifndef IBUILDER_HPP_
#define IBUILDER_HPP_

#pragma once
#include "include.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Parsing.hpp"

class IBuilder {
    public:
        virtual ~IBuilder() = default;
        virtual void createCamera(std::map<std::string,std::tuple<float,float,float>>) = 0;
        virtual void createLight(std::map<std::string,std::tuple<float,float,float>>) = 0;
        virtual void createObjects(std::vector<Primitive>) = 0;
        virtual const Scene &getScene() const = 0;
};

#endif /* !IBUILDER_HPP_ */