/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** SingletonLogger
*/

#include "SingletonLogger.hpp"

Logger* LoggerSingleton::instance = nullptr;

Logger* LoggerSingleton::getInstance() {
    if (instance == nullptr) {
        instance = new Logger("logfile.txt");
    }
    return instance;
}

void LoggerSingleton::destroyInstance() {
    delete instance;
    instance = nullptr;
}
