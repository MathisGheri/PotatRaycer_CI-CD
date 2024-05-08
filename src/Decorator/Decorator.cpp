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
#include "Exception.hpp"
#include <thread>

Decorator::Decorator(Scene scene)
{
    Logger* logger = LoggerSingleton::getInstance();
    logger->log(INFO, "Decorator created.");
    _world = scene.getObjects();
    _light = scene.getLight();
    _cam = scene.getCamera();
    _width = 800;
    _height = 400;
    _ns = 50;
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

void Decorator::colorThread(int x, int end_x, int y, int i, std::map<int, std::string>& maMap)
{
    std::string str;
    while (x < end_x)
    {
        Vec3 col(0, 0, 0);
        for (int s = 0; s < _ns; s++) {
            float u = float(x + drand48()) / float(_width);
            float v = float(y + drand48()) / float(_height);
            Ray r = _cam.get_Ray(u, v);

            col += colorloop(r, _world, _light);
        }
        col /= float(_ns);
        col = Vec3(sqrt(col.r()), sqrt(col.g()), sqrt(col.b()));
        int ir = int(255.99 * col[0]);
        int ig = int(255.99 * col[1]);
        int ib = int(255.99 * col[2]);

        str.append(std::to_string(ir) + " " + std::to_string(ig) + " " + std::to_string(ib) + "\n");
        x++;
    }
    maMap[i] = str;
}

void Decorator::loop(Scene scene)
{
    FileWatcher *watcher = FileWatcherSingleton::getInstance();
    std::map<int, std::string> maMap;
    int num_threads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    std::ofstream outFile("image.ppm");
    watcher->addObserver(this);

    Logger* logger = LoggerSingleton::getInstance();
    outFile << "P3\n" << _width << " " << _height << "\n255\n";
    for (int y = _height - 1; y >= 0; y--) {
        int x = 0, end_x = _width / num_threads, end;
        for (int i = 0; i < num_threads; i++) {
            end = end_x * (i + 1);
            if (i == num_threads - 1) end = _width;
            threads.emplace_back([this, x, end, y, i, &maMap](){
                this->colorThread(x, end, y, i, maMap);
            });
            x += end_x;
        }
        for (auto& t : threads) {
            if (t.joinable())
                t.join();
        }
        watcher->startWatching();
        if (_tomato == true) {
            _tomato = false;
            throw Exception("A modification has be detected generation will restart in 5 second", Level::LOW);
        }
        for (const auto& pair : maMap) {
            outFile << pair.second;
        }
    }
    outFile.close();
    logger->log(DEBUG, "End of loop.");
}

void Decorator::reset()
{
    _tomato = true;
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
        return Vec3(0, 0, 0);
    }
}
