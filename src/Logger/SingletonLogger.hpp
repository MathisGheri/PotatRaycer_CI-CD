/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** SingletonLogger
*/

/**
* @file SingletonLogger.hpp
* @brief File for the SingletonLogger class.
*/

#pragma once

#ifndef SINGLETONLOGGER_HPP_
#define SINGLETONLOGGER_HPP_

#include "Logger.hpp"

/**
* @class LoggerSingleton
* @brief Class used to create the SingletonLogger.
*/

class LoggerSingleton {
    private:
        static Logger* instance;
        LoggerSingleton() {}

    public:
        LoggerSingleton(const LoggerSingleton&) = delete;
        LoggerSingleton& operator=(const LoggerSingleton&) = delete;

        /**
        * @brief Get the instance of the Logger.
        * @return The instance of the Logger.
        */
        static Logger* getInstance();
        static void destroyInstance();
};

#endif /* !SINGLETONLOGGER_HPP_ */
