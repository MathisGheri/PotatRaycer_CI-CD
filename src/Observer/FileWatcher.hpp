/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** FileWatcher
*/

#ifndef FILEWATCHER_HPP_
#define FILEWATCHER_HPP_

#include "IObserver.hpp"

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
        void addObserver(IObserver* observer);
        void setFileToWatch(const std::string& fileToWatch);
        void removeObserver(IObserver* observer);
        void notifyObservers(const std::string& message);
        void startWatching();
        const std::string &getFile()
        {
            return _file;
        }

};

#endif /* !FILEWATCHER_HPP_ */
