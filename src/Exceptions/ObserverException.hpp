/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Exception
*/

#pragma once

#ifndef OBSERVEREXCEPTION_HPP_
#define OBSERVEREXCEPTION_HPP_

#include "include.hpp"
#include "Exception.hpp"


class ObserverException : public Exception {
public:
    ObserverException(const std::string& msg, Level lvl = Level::MIDDLE) : Exception(msg, lvl) {}
};

#endif /* !OBSERVEREXCEPTION_HPP_ */