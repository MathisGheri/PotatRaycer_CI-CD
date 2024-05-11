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
        void setLight(Light l);
        void setCamera(Camera c);
        void addObject(std::shared_ptr<IHitable> obj); //juste mettre dans le tableau
        // mettre des consts
        const std::vector<std::shared_ptr<IHitable>>& getObjects(void) const;
        const Light &getLight(void) const;
        const Camera &getCamera(void) const;
    private:
        Light light;
        Camera camera;
        std::vector<std::shared_ptr<IHitable>> objects; // tableau de Hitable
};

#endif /* !SCENE_HPP_ */