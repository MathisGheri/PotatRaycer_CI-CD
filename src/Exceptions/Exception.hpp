/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Exception
*/

/**
* @file Exception.hpp
* @brief File for the Exception class.
*/ 

#pragma once

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include "include.hpp"

/**
* @enum Level
* @brief Enum used to define the level of the exception.
*/

enum class Level {
    NONE,
    LOW,
    MIDDLE,
    HIGH
};

/**
* @class Exception
* @brief Class used to create the Exception. 
*/
class Exception {
    public:
        /**
        * @brief Construct a new Exception object
        * @param msg The message of the exception.
        * @param lvl The level of the exception.
        */
        Exception(const std::string& msg, Level lvl = Level::NONE) : message(msg), lvl(lvl) {}

        /**
        * @brief Get the message of the exception.
        * @return The message of the exception.
        */
        const char* what() const noexcept
        {
            return message.c_str();
        }

        /**
        * @brief Get the level of the exception.
        * @return The level of the exception.
        */
        Level getLevel() const {
            return this->lvl;
        }
    private:
        std::string message;
        Level lvl;
};

#endif /* !EXCEPTION_HPP_ */
