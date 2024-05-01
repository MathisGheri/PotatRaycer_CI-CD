/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Scene
*/

#include <iostream>
#include <vector>

#include "../Camera/Camera.hpp"
#include "../Light/Light.hpp"
#include "../Primitives/IHitable.hpp"
//#include "../Primitives/" //sphere etc

#ifndef SCENE_HPP_
#define SCENE_HPP_
//pedro pedro pedro
class Scene {
    public:
        Scene();
        ~Scene();
        void setLight(Light *l);
        void setCamera(Camera *c);
        void addObject(IHitable *obj); //juste mettre dans le tableau
        // mettre des consts
        std::vector<IHitable *> getObjects(void);
        Light *getLight(void);
        Camera *getCamera(void);
    private:
        Light *light;
        Camera *camera;
        std::vector<IHitable *> Objects; // tableau de Hitable
};

#endif /* !SCENE_HPP_ */
