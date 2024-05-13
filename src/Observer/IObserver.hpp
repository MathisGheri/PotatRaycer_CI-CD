/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IObserver
*/

/**
* @file IObserver.hpp
* @brief Interface for Observers used to monitor changes in configuration files.
*/

#ifndef IOBSERVER_HPP_
#define IOBSERVER_HPP_

#include <sys/inotify.h>
#include <unistd.h>
#include <sys/select.h>
#include <list>
#include <iostream>
#include <string>
#include <thread>

/**
* @class IObserver
* @brief Interface for Observers used to monitor changes in configuration files.
*/

class IObserver {
    public:
        virtual ~IObserver() {}

        /**
        * @note This function allow the code to reset the generation when there is a modification in the configuration file.
        */
        virtual void reset() = 0;
};


#endif /* !IOBSERVER_HPP_ */
