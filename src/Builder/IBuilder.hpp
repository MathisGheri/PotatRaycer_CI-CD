/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** IBuilder
*/

#ifndef IBUILDER_HPP_
#define IBUILDER_HPP_

class IBuilder {
    public:
        ~IBuilder() = 0;
        virtual void createLight() = 0; //implement better with return value
        virtual void createCamera() = 0; //implement better with return value
        virtual void createObject(Hitable *object) = 0;
        virtual void getScene() = 0;
};

//reimplement totaly the createLight function
//get back the createCamera we have to understand code
#endif /* !IBUILDER_HPP_ */
