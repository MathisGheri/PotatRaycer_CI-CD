/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IDecorator
*/

#ifndef IDECORATOR_HPP_
#define IDECORATOR_HPP_

#include "IMaterial.hpp"
#include "IHitable.hpp"

class IDecorator {
    public:
        virtual ~IDecorator() = default;
        //virtual void setTexture() = 0; //not sure
    private:
    std::unique_ptr<Objects> obj;
    std::vector<std::unique_ptr<IHitable>> hitable;
}
#endif /* !IDECORATOR_HPP_ */
