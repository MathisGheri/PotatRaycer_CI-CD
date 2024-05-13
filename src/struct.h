/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** struct
*/

/**
* @file struct.h
* @brief Struct for hit record.
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "Vec2.hpp"
class IMaterial;

/**
* @struct hit_record_t
* @brief Structure for storing hit record information.
*
* The hit_record_t structure is used to store information about a ray-object intersection.
* It includes the intersection point, the normal at the intersection, the material of the
* intersected object, and other relevant data.
*/
/**
* @struct hit_record_s
* @brief Structure for storing hit record information.
*
* The hit_record_t structure is used to store information about a ray-object intersection.
* It includes the intersection point, the normal at the intersection, the material of the
* intersected object, and other relevant data.
*/
typedef struct hit_record_s {
    float t; ///< The parameter value at which the intersection occurs.
    Vec3 p; ///< The intersection point in 3D space.
    Vec3 normal; ///< The normal vector at the intersection point.
    std::shared_ptr<IMaterial> mat_ptr; ///< Pointer to the material of the intersected object.
    Vec2 uv; ///< Texture coordinates at the intersection point.
} hit_record_t;

#endif /* !STRUCT_H_ */
