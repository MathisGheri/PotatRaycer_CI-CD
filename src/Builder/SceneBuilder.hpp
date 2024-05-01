/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** SceneBuilder
*/

#pragma once
#include "IBuilder.hpp"
#include "../Camera/Camera.hpp"
#include "../Light/Light.hpp"
#include "../Primitives/IHitable.hpp"
#include "Metal.hpp"
#include "Lambertian.hpp"
#include "Dielectric.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include <memory>
#include <iostream>
#include <utility>

#ifndef SCENEBUILDER_HPP_
#define SCENEBUILDER_HPP_

class SceneBuilder : public IBuilder {
    public:
        SceneBuilder();
        ~SceneBuilder();
        void createCamera(std::map<std::string,std::tuple<float,float,float>>) override final; //implement better with return value
        void createLight(std::map<std::string,std::tuple<float,float,float>>) override final; //implement better with return value
        void createObjects(std::vector<Primitive>) override final;
        //SceneBuilder addObject();
        Scene *getScene() override final;
    private:
        Scene *scene;
};

#endif /* !SCENEBUILDER_HPP_ */
