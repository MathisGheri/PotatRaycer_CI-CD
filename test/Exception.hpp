/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Exception
*/

#pragma once

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include "include.hpp"

enum class Level {
    NONE,
    LOW,
    MIDDLE,
    HIGH
};

class Exception {
    public:
    Exception(const std::string& msg, Level lvl = Level::LOW) : message(msg), lvl(lvl) {}
        virtual const char* what() const noexcept
        {
            return message.c_str();
        }
        Level getLevel() const {
        return this->lvl;
        }
    private:
        std::string message;
        Level lvl;
};

#endif /* !EXCEPTION_HPP_ */
