/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Exception
*/

/**
* @file ObserverException.hpp
* @brief File for the Observer, to make his own exception.
*/

#pragma once

#ifndef OBSERVEREXCEPTION_HPP_
#define OBSERVEREXCEPTION_HPP_

#include "include.hpp"
#include "Exception.hpp"

/**
* @class ObserverException
* @brief Class used to create the ObserverException.
*/
class ObserverException : public Exception {
public:
    /**
    * @brief Construct a new Observer Exception object
    * @param msg The message of the exception.
    * @param lvl The level of the exception.
    * @details This function is the constructor of the ObserverException class.
    */
    ObserverException(const std::string& msg, Level lvl = Level::MIDDLE) : Exception(msg, lvl) {}
};

#endif /* !OBSERVEREXCEPTION_HPP_ */