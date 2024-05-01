/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Color
*/

#include "../Vec3/Vec3.hpp"
#include "../Ray/Ray.hpp"
#include "../Primitives/IHitable.hpp"
#include "../Calculus/Physics.hpp"

Vec3 color(const Ray& r, hitable *world, int depth)
{
    hit_record_t_t rec;
    if (world->hit(r, 0.001, MAXFLOAT, rec)) {
        Ray scattered;
        Vec3 attenuation;
        if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
            return attenuation * color(scattered, world, depth + 1);
        } else {
            return Vec3(0, 0, 0);
        }
    } else {
        Vec3 unit_dir = unit_vector(r.direction());
        float t = 0.5 * (unit_dir.y() + 1.0);
        return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
    }
}