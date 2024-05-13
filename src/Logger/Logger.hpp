/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Logger
*/

/**
* @file Logger.hpp
* @brief File for the Logger class.
*/

#pragma once

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include "include.hpp"

/**
* @enum LogLevel
* @brief Enum used to define the level of the log.
*/

enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

/**
* @class Logger
* @brief Class used to create the Logger.
*/

class Logger {
    private:
        std::ofstream logFile;

        /**
        * @brief Convert the log level to a string.
        * @param level The level of the log.
        * @return The string of the log level.
        */
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
        std::string _filename;
    public:
        Logger(const std::string& filename) {
            logFile.open(filename, std::ios::trunc);
            _filename = filename;
        }
        ~Logger() {
            logFile.close();
        }

        /**
        * @brief Set the state of the logger.
        * @param state The state of the logger.
        */
        void setState(bool state) {
            if (!state) {
                logFile.close();
            }
        }

        /**
        * @brief Log a message.
        * @param level The level of the log.
        * @param message The message of the log.
        */
        void log(LogLevel level, const std::string& message) {
            std::time_t now = std::time(0);
            std::tm* timeinfo = std::localtime(&now);
            char timestamp[20];
            std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
            std::ostringstream logEntry;
            logEntry << "[" << timestamp << "] "
                    << levelToString(level) << ": " << message << std::endl;
            if (logFile.is_open()) {
                logFile << logEntry.str();
                logFile.flush();
            }
        }
};

#endif /* !LOGGER_HPP_ */
