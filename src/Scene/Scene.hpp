/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Scene
*/
#pragma once

#ifndef SCENE_HPP_
#define SCENE_HPP_
//pedro pedro pedro

#include "Light.hpp"
#include "Camera.hpp"
#include "IHitable.hpp"
#include "include.hpp"

class Scene {
    public:
        Scene();
        ~Scene();
        void setLight(std::unique_ptr<Light>l);
        void setCamera(std::unique_ptr<Camera> c);
        void addObject(std::unique_ptr<IHitable> obj); //juste mettre dans le tableau
        // mettre des consts
        std::vector<IHitable*>& getObjects();
        Light *getLight(void);
        Camera *getCamera(void);
    private:
        std::unique_ptr<Light> light;
        std::unique_ptr<Camera >camera;
        std::vector<std::unique_ptr<IHitable>> Objects; // tableau de Hitable
};

#endif /* !SCENE_HPP_ */
