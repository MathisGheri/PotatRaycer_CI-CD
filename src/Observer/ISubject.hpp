/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** ISubject
*/

#pragma once

#ifndef ISUBJECT_HPP_
#define ISUBJECT_HPP_

#include "include.hpp"
#include "IObserver.hpp"

class ISubject {
    public:
        virtual ~ISubject() {}
        void addObserver(IObserver* observer)
        {
            observers.push_back(observer);
        }
        void removeObserver(IObserver* observer)
        {
            observers.remove(observer);
        }
        void notifyObservers(LogLevel level, const std::string& message)
        {
            for (auto& observer : observers) {
                observer->update(level, message);
            }
        }
    private:
        std::list<IObserver*> observers;
};

#endif /* !ISUBJECT_HPP_ */
