/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Logger
*/

#pragma once

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include "include.hpp"

enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class Logger {
private:
    std::ofstream logFile;
    std::string levelToString(LogLevel level)
    {
        switch (level) {
            case DEBUG: return "DEBUG";
            case INFO: return "INFO";
            case WARNING: return "WARNING";
            case ERROR: return "ERROR";
            case CRITICAL: return "CRITICAL";
            default: return "UNKNOWN";
        }
    }
public:
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios::app);
        if (!logFile.is_open()) {
            std::cerr << "Error opening log file." << std::endl;
        }
    }
    ~Logger() {
        logFile.close();
    }
    void log(LogLevel level, const std::string& message) {
        std::time_t now = std::time(0);
        std::tm* timeinfo = std::localtime(&now);
        char timestamp[20];
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
        std::ostringstream logEntry;
        logEntry << "[" << timestamp << "] "
                 << levelToString(level) << ": " << message << std::endl;

        //std::cout << logEntry.str();

        if (logFile.is_open()) {
            logFile << logEntry.str();
            logFile.flush();
        }
    }
};

#endif /* !LOGGER_HPP_ */
