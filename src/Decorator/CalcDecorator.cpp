/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** calcdeco
*/

#include "CalcDecorator.hpp"
#include "Camera.hpp"
#include "Light.hpp"

calcdeco::calcdeco(Scene *scene)
{
    auto hitable = std::move(scene->getObjects());
    _world.reserve(hitable.size());
    for (auto& obj : hitable)
        _world.emplace_back(std::move(obj));
    _light = std::move(scene->getLight());
    _cam = std::move(scene->getCamera());
    _width = 200;
    _height = 100;
}

calcdeco::~calcdeco() {}

void calcdeco::loop(Scene *scene)
{
    for (int y = _height - 1; y >= 0; y--) {
        for (int x = 0; x < _width; x++) {
            Vec3 col(0, 0, 0);
            for (int s = 0; s < _ns; s++) {
                float u = float(x + drand48()) / float(_width);
                float v = float(y + drand48()) / float(_height);
                Ray r = _cam->get_Ray(u, v);
                Vec3 p = r.point_at_parameter(2.0);
                col += colorloop(r, _world, scene->getLight());

                }
            col /= float(_ns);
            col = Vec3(sqrt(col.r()), sqrt(col.g()), sqrt(col.b()));
            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}

Vec3 colorloop(const Ray &r, const std::vector<std::unique_ptr<IHitable>> & _world, std::unique_ptr<Light> _light)
{
    if (_world.size() == 0) {
        // Aucun objet dans le monde
        return Vec3(0, 0, 0);
    }

    int depth = 0;
    hit_record_t rec;
    Ray scattered, temp_r = r;
    Vec3 attenuation, temp;
    if (_world[0]->hit(r, 0.001, MAXFLOAT, rec)) {
        bool cond = false;
        cond = rec.mat_ptr->scatter(temp_r, rec, attenuation, scattered, *_light, _world);

        depth++;
        temp = attenuation;
        if (!(_world[0]->hit(temp_r, 0.001, MAXFLOAT, rec))) {
            if (cond)
                return temp;
            else
                return Vec3(0.0, 0.0, 0.0);
        }
        if (cond)
            return temp;
        temp_r = scattered;
        while (depth < 50) {
            cond = rec.mat_ptr->scatter(temp_r, rec, attenuation, scattered, *_light, _world);

            depth++;
            temp *= attenuation;
            if (!(_world[0]->hit(temp_r, 0.001, MAXFLOAT, rec))) {
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
        Vec3 unit_dir = unit_vector(r.direction());
        float t = 0.5 * (unit_dir.y() + 1.0);
        return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
    }
}
