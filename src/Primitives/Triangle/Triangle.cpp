/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Triangle
*/

#include "Triangle.hpp"

Triangle::Triangle(const Vec3& v0, const Vec3& v1, const Vec3& v2, const Vec2& uv0, const Vec2& uv1, const Vec2& uv2, std::shared_ptr<IMaterial> m)
: _v0(v0), _v1(v1), _v2(v2), _uv0(uv0), _uv1(uv1), _uv2(uv2), _mat_ptr(m) {}

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
        float w = 1.0f - u - v; // Coordonnée barycentrique pour le troisième sommet
        rec.uv = _uv0 * w + _uv1 * u + _uv2 * v; // Interpolation des coordonnées UV
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
    // Conversion des angles de rotation en radians
    float radX = rotation.e[0] * M_PI / 180.0f;
    float radY = rotation.e[1] * M_PI / 180.0f;
    float radZ = rotation.e[2] * M_PI / 180.0f;

    // Calcul des sinus et cosinus pour chaque axe
    float cosX = cos(radX), sinX = sin(radX);
    float cosY = cos(radY), sinY = sin(radY);
    float cosZ = cos(radZ), sinZ = sin(radZ);

    // Rotation autour de l'axe X
    float y1 = vertex.e[1] * cosX - vertex.e[2] * sinX;
    float z1 = vertex.e[1] * sinX + vertex.e[2] * cosX;

    // Rotation autour de l'axe Y
    float x2 = vertex.e[0] * cosY + z1 * sinY;
    float z2 = -vertex.e[0] * sinY + z1 * cosY;

    // Rotation autour de l'axe Z
    float x3 = x2 * cosZ - y1 * sinZ;
    float y3 = x2 * sinZ + y1 * cosZ;

    return Vec3(x3, y3, z2);
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
