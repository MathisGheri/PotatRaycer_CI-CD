/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** SceneBuilder
*/

#include "IBuilder.hpp"
#include "../Scene/Scene.hpp"
#include "../Camera/Camera.hpp"
#include "../Light/Light.hpp"
#include "../Primitives/IHitable.hpp"

#ifndef SCENEBUILDER_HPP_
#define SCENEBUILDER_HPP_

class SceneBuilder : public IBuilder {
    public:
        SceneBuilder();
        ~SceneBuilder();
        void createLight() override final; //implement better with return value
        void createCamera() override final; //implement better with return value
        void createObject(IHitable *object) override final;
        //SceneBuilder addObject();
        Scene *getScene() override final;
    private:
        Scene *scene;
};

#endif /* !SCENEBUILDER_HPP_ */
