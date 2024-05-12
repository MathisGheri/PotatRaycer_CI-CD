/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** calcs
*/

#ifndef ComputeRATOR_HPP_
#define ComputeRATOR_HPP_

#include "Scene.hpp"
#include "Ray.hpp"
#include "IMaterial.hpp"
#include "SFML/Graphics.hpp"
#include "FileWatcherSingleton.hpp"

class Compute : public IObserver{
    public:
        Compute(Scene scene);
        ~Compute();
        void loop(Scene scene);
        Vec3 colorloop(const Ray &r, const std::vector<std::shared_ptr<IHitable>> &_objects, Light _light);
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const ;
        void colorThread(int x, int end_x, int y, int i, std::map<int, std::string>& maMap, sf::Image &image);
        void reset() override final;
    private:
        std::vector<std::shared_ptr<IHitable>> _world;
        Light _light;
        Camera _cam;
        int _width;
        int _height;
        bool _tomato = false;
        int _ns;
};

#endif /* DecoratorRATOR_HPP_ */
