/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IObserver
*/

#pragma once

#ifndef IOBSERVER_HPP_
#define IOBSERVER_HPP_

#include "include.hpp"

class IObserver {
    public:
        virtual ~IObserver() {}
        virtual void update(LogLevel level, const std::string& message) = 0;
};

#endif /* !IOBSERVER_HPP_ */
