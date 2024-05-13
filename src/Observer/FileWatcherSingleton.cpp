/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** FileWatcherSingleton
*/

#include "FileWatcherSingleton.hpp"

FileWatcher* FileWatcherSingleton::instance = nullptr;

FileWatcher *FileWatcherSingleton::getInstance()
{
    if (instance == nullptr) {
        instance = new FileWatcher();
    }
    return instance;
}

void FileWatcherSingleton::destroyInstance()
{
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}