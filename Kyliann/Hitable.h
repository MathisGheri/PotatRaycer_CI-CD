#ifndef HITABLEH
#define HITABLEH

#include "Ray.h"

class material;

struct hit_record_t {
	float t;
	Vec3 p;
	Vec3 normal;
	material *mat_ptr;
};

class hitable {
public:
	virtual bool hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const = 0;
};

#endif
