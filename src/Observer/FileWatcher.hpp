/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** FileWatcher
*/

/**
* @file FileWatcher.hpp
* @brief Class for watching changes in configuration files.
*/

#ifndef FILEWATCHER_HPP_
#define FILEWATCHER_HPP_

#include "IObserver.hpp"

/**
* @class FileWatcher
* @brief Class for watching changes in configuration files.
*/

class FileWatcher {
    private:
        int fd;
        int wd;
        std::list<IObserver*> observers;
        void handleEvents();
        std::string _file;

    public:
        FileWatcher() {}
        ~FileWatcher();

        /**
        * @brief Add an observer to the list of observers.
        * @param observer The observer to add.
        */
        void addObserver(IObserver* observer);

        /**
         * @brief Set the file to watch.
         * @param fileToWatch The file to watch.
         */
        void setFileToWatch(const std::string& fileToWatch);

        /**
        * @brief Remove an observer from the list of observers.
        * @param observer The observer to remove.
        */
        void removeObserver(IObserver* observer);

        /**
        * @brief Notify all observers.
        * @param message The message to send to the observers.
        */
        void notifyObservers(const std::string& message);

        /**
        * @brief Start watching the file.
        */
        void startWatching();

        /**
        * @brief Get the file to watch.
        * @return The file to watch.
        */
        const std::string &getFile()
        {
            return _file;
        }

};

#endif /* !FILEWATCHER_HPP_ */
