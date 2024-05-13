/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include "IHitable.hpp"

/**
* @class Triangle
* @brief Class for handling triangles.
*/

class Triangle : public IHitable {
    public:
        Triangle(const Vec3& v0, const Vec3& v1, const Vec3& v2, const Vec2& uv0, const Vec2& uv1, const Vec2& uv2);
        ~Triangle();
        bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const;
        std::shared_ptr<IMaterial> getMaterial() { return _mat_ptr; }

        /**
        * @brief Transform the vectors of triangle based on the value given.
        * @param scale The scale value.
        * @param rotation The rotation value.
        * @param position The position value.
        */
        void transform(const Vec3& scale, const Vec3& rotation, const Vec3& position);

        /**
        * @brief Apply the transformation to a vertex.
        * @param vertex The vertex to transform.
        * @param scale The scale value.
        * @param rotation The rotation value.
        * @param position The position value.
        * @return Vec3 The transformed vertex.
        */
        Vec3 applyTransform(const Vec3& vertex, const Vec3& scale, const Vec3& rotation, const Vec3& position);
        void setMaterial(std::shared_ptr<IMaterial> m) { _mat_ptr = m; };
    private:
        Vec3 _v0, _v1, _v2; ///< Vertices of the triangle.
        Vec2 _uv0, _uv1, _uv2; ///< Texture coordinates of the texture.
        std::shared_ptr<IMaterial> _mat_ptr; ///< Pointer to the material of the intersected object.
        Vec3 _pos; ///< Position of the triangle.
};

#endif /* !TRIANGLE_HPP_ */
