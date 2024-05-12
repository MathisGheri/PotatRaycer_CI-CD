/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** FileWatcher
*/

#include "FileWatcher.hpp"

FileWatcher::~FileWatcher()
{
    inotify_rm_watch(fd, wd);
    close(fd);
}

void FileWatcher::addObserver(IObserver* observer)
{
    observers.push_back(observer);
}

void FileWatcher::removeObserver(IObserver* observer)
{
    observers.remove(observer);
}

void FileWatcher::notifyObservers(const std::string& message)
{
    for (IObserver* observer : observers) {
        observer->reset();
    }
}

void FileWatcher::setFileToWatch(const std::string& fileToWatch)
{
    _file = fileToWatch;
    fd = inotify_init();
    if (fd < 0) {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }
    wd = inotify_add_watch(fd, fileToWatch.c_str(), IN_MODIFY);
    if (wd == -1) {
        perror("inotify_add_watch");
        exit(EXIT_FAILURE);
    }
}

void FileWatcher::startWatching()
{
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(fd, &fds);
    struct timeval timeout = {0, 0};
    int ret = select(fd + 1, &fds, NULL, NULL, &timeout);
    if (ret < 0) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (ret > 0) {
        if (FD_ISSET(fd, &fds)) {
            handleEvents();
        }
    }
}

void FileWatcher::handleEvents()
{
    char buffer[1024 * (sizeof(struct inotify_event) + 16)];
    int length = read(fd, buffer, sizeof(buffer));
    if (length < 0) {
        perror("read");
        return;
    }
    int i = 0;
    while (i < length) {
        struct inotify_event *event = (struct inotify_event *)&buffer[i];
        if (event->mask & IN_MODIFY) {
            notifyObservers("Configuration file modified.");
        }
        i += sizeof(struct inotify_event) + event->len;
    }
}
