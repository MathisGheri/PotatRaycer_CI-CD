/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** calcs
*/

/**
* @file Computing.hpp
* @brief Header file for the Compute class.
*/

#ifndef ComputeRATOR_HPP_
#define ComputeRATOR_HPP_

#include "Scene.hpp"
#include "Ray.hpp"
#include "IMaterial.hpp"
#include "SFML/Graphics.hpp"
#include "FileWatcherSingleton.hpp"
#include "ILight.hpp"

/**
* @class Compute
* @brief Class used to compute the image.
*/

class Compute : public IObserver {
    public:
        Compute(Scene scene);
        ~Compute();

        /**
        * @brief Loop function to compute the image.
        * @param scene The scene to compute.
        * 
        * @details This function iniate all the calcul to compute the image of the scene.
        */ 
        void loop(Scene scene);

        /**
        * @brief Function to compute the color of the pixel.
        * @param r The ray.
        * @param _objects The objects in the scene.
        * @param _light The light in the scene.
        * @return The color of the pixel.
        */
        Vec3 colorloop(const Ray &r, const std::vector<std::shared_ptr<IHitable>> &_objects, std::shared_ptr<ILight> _light);

        /**
        * @brief Function to check if the object has been hit by the Ray.
        * @param r The ray.
        * @param t_min The minimum value of the distance between elements.
        * @param t_max The maximum value of the distance between elements.
        * @param rec The hit record (all the elements).
        * @return True if the object has been hit, false otherwise.
        */
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const ;

        /**
        * @brief Function to compute the color of the pixel.
        * @param x The x position of the pixel.
        * @param end_x The end x position of the pixel.
        * @param y The y position of the pixel.
        * @param i The number of the thread.
        * @param maMap The map of the colors.
        * @param image The SFML image to render in real time.
        */ 
        void colorThread(int x, int end_x, int y, int i, std::map<int, std::string>& maMap, sf::Image &image);
        void reset() override final;
    private:
        std::vector<std::shared_ptr<IHitable>> _world;
        std::shared_ptr<ILight> _light;
        Camera _cam;
        int _width;
        int _height;
        bool _change = false;
        int _ns;
};

#endif /* DecoratorRATOR_HPP_ */
