/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IObserver
*/

#ifndef IOBSERVER_HPP_
#define IOBSERVER_HPP_

#include <sys/inotify.h>
#include <unistd.h>
#include <sys/select.h>
#include <list>
#include <iostream>
#include <string>
#include <thread>

class IObserver {
    public:
        virtual ~IObserver() {}
        virtual void reset() = 0;
};


#endif /* !IOBSERVER_HPP_ */
