/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Decorator
*/

#include "Decorator.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "SingletonLogger.hpp"

Decorator::Decorator(Scene scene)
{
    Logger* logger = LoggerSingleton::getInstance();
    logger->log(INFO, "Decorator created.");
    _world = scene.getObjects();
    _light = scene.getLight();
    _cam = scene.getCamera();
    _width = 200;
    _height = 100;
    _ns = 5;
}

Decorator::~Decorator() {}

bool Decorator::hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const {
    hit_record_t temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;
    for(int i = 0; i < _world.size(); i++) {
        if (_world[i]->hit(r,t_min,closest_so_far,temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}

void Decorator::loop(Scene scene)
{
    Logger* logger = LoggerSingleton::getInstance();
    #pragma omp parallel for collapse(2) schedule(dynamic, 1)
    std::cout << "P3\n" << _width << " " << _height << "\n255\n";
    for (int y = _height - 1; y >= 0; y--) {
        for (int x = 0; x < _width; x++) {
            Vec3 col(0, 0, 0);
            for (int s = 0; s < _ns; s++) {
                float u = float(x + drand48()) / float(_width);
                float v = float(y + drand48()) / float(_height);
                Ray r = _cam.get_Ray(u, v);
                // std::cout << "S S S " << r.direction() << " ::RAY:: " << r.origin() << std::endl;
                col += colorloop(r, _world, _light);
            }
            col /= float(_ns);
            col = Vec3(sqrt(col.r()), sqrt(col.g()), sqrt(col.b()));
            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);
            #pragma omp critical
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    logger->log(DEBUG, "End of loop.");
}

Vec3 Decorator::colorloop(const Ray &r, const std::vector<std::shared_ptr<IHitable>> &_world, Light _light)
{
    int depth = 0;
    hit_record_t rec;
    Ray scattered, temp_r = r;
    Vec3 attenuation, temp;
    if (hit(temp_r, 0.001, MAXFLOAT, rec)) {
        bool cond = false;
        cond = rec.mat_ptr->scatter(temp_r, rec, attenuation, scattered, _light, _world);

        depth++;
        temp = attenuation;
        if (!(hit(temp_r, 0.001, MAXFLOAT, rec))) {
            if (cond)
                return temp;
            else
                return Vec3(0.0, 0.0, 0.0);
        }
        if (cond)
            return temp;
        temp_r = scattered;
        while (depth < 50) {
            cond = rec.mat_ptr->scatter(temp_r, rec, attenuation, scattered, _light, _world);

            depth++;
            temp *= attenuation;
            if (!(hit(temp_r, 0.001, MAXFLOAT, rec))) {
                if (cond)
                    return temp;
                else
                    return Vec3(0.0, 0.0, 0.0);
            }
            if (cond)
                return temp;
            temp_r = scattered;
        }
        return temp;
    } else {
        // std::cout << "ff" << std::endl;
        return Vec3(0, 0, 0);
    }
}
