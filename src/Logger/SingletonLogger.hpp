/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** SingletonLogger
*/

#pragma once

#ifndef SINGLETONLOGGER_HPP_
#define SINGLETONLOGGER_HPP_

#include "Logger.hpp"

class LoggerSingleton {
private:
    static Logger* instance;
    LoggerSingleton() {}

public:
    LoggerSingleton(const LoggerSingleton&) = delete;
    LoggerSingleton& operator=(const LoggerSingleton&) = delete;

    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger("logfile.txt");
        }
        return instance;
    }

    static void destroyInstance() {
        delete instance;
        instance = nullptr;
    }
};

Logger* LoggerSingleton::instance = nullptr;

#endif /* !SINGLETONLOGGER_HPP_ */
