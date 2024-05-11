/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Triangle
*/

#include "Triangle.hpp"

Triangle::Triangle(const Vec3& v0, const Vec3& v1, const Vec3& v2/*, Vec3 position*/, std::shared_ptr<IMaterial> m)
: _v0(v0/* + position*/), _v1(v1/* + position*/), _v2(v2/* + position*/), /*_pos(position),*/ _mat_ptr(m) {}

Triangle::~Triangle() {}

bool Triangle::hit(const Ray& ray, float t_min, float t_max, hit_record_t& rec) const
{
    Vec3 edge1 = _v1 - _v0;
    Vec3 edge2 = _v2 - _v0;
    Vec3 h = cross(ray.direction(), edge2);
    float a = dot(edge1, h);

    if (a > -0.0001f && a < 0.0001f)
        return false;

    float f = 1.0 / a;
    Vec3 s = ray.origin() - _v0;
    float u = f * dot(s, h);
    if (u < 0.0 || u > 1.0)
        return false;

    Vec3 q = cross(s, edge1);
    float v = f * dot(ray.direction(), q);
    if (v < 0.0 || u + v > 1.0)
        return false;

    float t = f * dot(edge2, q);
    if (t > t_min && t < t_max) {
        rec.t = t;
        rec.p = ray.point_at_parameter(t);
        rec.normal = cross(edge1, edge2).normalize();
        rec.mat_ptr = _mat_ptr.get();
        return true;
    }

    return false;
}

void Triangle::transform(const Vec3& scale, const Vec3& rotation, const Vec3& position)
{
    _v0 = applyTransform(_v0, scale, rotation, position);
    _v1 = applyTransform(_v1, scale, rotation, position);
    _v2 = applyTransform(_v2, scale, rotation, position);
}

Vec3 scaleVertex(const Vec3& vertex, const Vec3& scale)
{
    return Vec3(vertex.e[0] * scale.e[0], vertex.e[1] * scale.e[1], vertex.e[2] * scale.e[2]);
}

Vec3 rotateVertex(const Vec3& vertex, const Vec3& rotation)
{
    float rad = rotation.e[2] * M_PI / 180.0f;

    float cosTheta = cos(rad);
    float sinTheta = sin(rad);

    return Vec3(
        vertex.e[0] * cosTheta + vertex.e[2] * sinTheta,
        vertex.e[1],
        -vertex.e[0] * sinTheta + vertex.e[2] * cosTheta
    );
}

Vec3 translateVertex(const Vec3& vertex, const Vec3& position)
{
    return Vec3(vertex.e[0] + position.e[0], vertex.e[1] + position.e[1], vertex.e[2] + position.e[2]);
}

Vec3 Triangle::applyTransform(const Vec3& vertex, const Vec3& scale, const Vec3& rotation, const Vec3& position) {
    Vec3 scaled = scaleVertex(vertex, scale);
    Vec3 rotated = rotateVertex(scaled, rotation);
    return translateVertex(rotated, position);
}
