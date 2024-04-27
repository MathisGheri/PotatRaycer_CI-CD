/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Scene
*/

#include <iostream>
#include "Camera.h"

#ifndef SCENE_HPP_
#define SCENE_HPP_

class Scene {
    public:
        Scene(); //mettre light etc.. à nullptdr
        ~Scene();
        void setLight(Light *l);
        void setCamera(Camera *c);
        void addObject(Hitable *obj); //juste mettre dans le tableau
        // mettre des consts
        std::vector<Hitable *> getObjects(void);
        Light *getLight(void);
        Camera *getCamera(void);
    protected:
    private:
        Light *light;
        Camera *camera;
        std::vector<Hitable *> Objects; // tableau de Hitable
};

#endif /* !SCENE_HPP_ */
