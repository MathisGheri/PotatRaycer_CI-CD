/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Decorator
*/

#pragma once

#ifndef DECORATOR_HPP_
#define DECORATOR_HPP_

#include "IHitable.hpp"

class Decorator : public IHitable{
    public:
        Decorator();
        ~Decorator();

    protected:
        std::shared_ptr<IHitable> primitive;
    private:
};

#endif /* !DECORATOR_HPP_ */
