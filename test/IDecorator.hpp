/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IDecorator
*/

#ifndef IDECORATOR_HPP_
#define IDECORATOR_HPP_

#include "IHitable.hpp"

class IDecorator {
    public:
        virtual ~IDecorator() = default;
        //virtual void setTexture() = 0; //not sure
};

#endif /* !IDECORATOR_HPP_ */
