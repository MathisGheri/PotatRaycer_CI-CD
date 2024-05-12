/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include "IHitable.hpp"

class Triangle : public IHitable {
    public:
        Triangle(const Vec3& v0, const Vec3& v1, const Vec3& v2, const Vec2& uv0, const Vec2& uv1, const Vec2& uv2);
        ~Triangle();
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const;
        std::shared_ptr<IMaterial> getMaterial() { return _mat_ptr; }
        void transform(const Vec3& scale, const Vec3& rotation, const Vec3& position);
        Vec3 applyTransform(const Vec3& vertex, const Vec3& scale, const Vec3& rotation, const Vec3& position);
        void setMaterial(std::shared_ptr<IMaterial> m) { _mat_ptr = m; };
    private:
        Vec3 _v0, _v1, _v2;
        Vec2 _uv0, _uv1, _uv2;
        std::shared_ptr<IMaterial> _mat_ptr;
        Vec3 _pos;
};

#endif /* !TRIANGLE_HPP_ */
