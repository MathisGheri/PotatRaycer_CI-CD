/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** FileWatcherSingleton
*/

/**
* @file FileWatcherSingleton.hpp
* @brief Singleton for the FileWatcher class.
*/

#ifndef FILEWATCHERSINGLETON_HPP_
#define FILEWATCHERSINGLETON_HPP_

#include "FileWatcher.hpp"

/**
* @class FileWatcherSingleton
* @brief Singleton for the FileWatcher class.
*/

class FileWatcherSingleton {
    public:
        FileWatcherSingleton(const FileWatcherSingleton&) = delete;
        FileWatcherSingleton& operator=(const FileWatcherSingleton&) = delete;

        /**
        * @brief Get the instance of the singleton.
        * @return The instance of the singleton.
        */
        static FileWatcher* getInstance();
        static void destroyInstance();

    private:
        static FileWatcher* instance;
        FileWatcherSingleton() {}
};

#endif /* !FILEWATCHERSINGLETON_HPP_ */
