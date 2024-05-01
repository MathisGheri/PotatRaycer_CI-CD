/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IBuilder
*/

#pragma once
#include "../Primitives/IHitable.hpp"
#include "../Scene/Scene.hpp"
#include "../Parsing/Parsing.hpp"

#ifndef IBUILDER_HPP_
#define IBUILDER_HPP_

class IBuilder {
    public:
        virtual ~IBuilder();
        virtual void createLight(std::map<std::string,std::tuple<float,float,float>>) = 0; //implement better with return value
        virtual void createCamera(std::map<std::string,std::tuple<float,float,float>>) = 0; //implement better with return value
        virtual void createObjects(std::vector<Primitive>) = 0;
        virtual Scene *getScene() = 0;
};

//reimplement totaly the createLight function
//get back the createCamera we have to understand code
#endif /* !IBUILDER_HPP_ */
