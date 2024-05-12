/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** FileWatcherSingleton
*/

#ifndef FILEWATCHERSINGLETON_HPP_
#define FILEWATCHERSINGLETON_HPP_

#include "FileWatcher.hpp"

class FileWatcherSingleton {
    public:
        FileWatcherSingleton(const FileWatcherSingleton&) = delete;
        FileWatcherSingleton& operator=(const FileWatcherSingleton&) = delete;
        static FileWatcher* getInstance();

        static void destroyInstance();

    private:
        static FileWatcher* instance;
        FileWatcherSingleton() {}
};

#endif /* !FILEWATCHERSINGLETON_HPP_ */
