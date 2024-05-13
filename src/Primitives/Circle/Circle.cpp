#include "Circle.hpp"
#include "SingletonLogger.hpp"

Circle::Circle(Vec3 pos, Vec3 norm, float r) : position(pos), normal(norm), radius(r) {
    Logger *logger = LoggerSingleton::getInstance();
    std::ostringstream msg;
    msg << "LOG: Circle created with these params. pos = " << pos << ", normal = " << norm << ", r = " << r << ".";
    logger->log(INFO, msg.str());
}

Circle::~Circle() {}

void Circle::setMaterial(std::shared_ptr<IMaterial> m) {
    mat_ptr = std::move(m);
}

std::shared_ptr<IMaterial> Circle::getMaterial() {
    return mat_ptr;
}

bool Circle::hit(const Ray& r, float t_min, float t_max, hit_record_t& rec) const {
    // Vérifier si le rayon intersecte le plan du cercle
    float denom = dot(normal, r.getDirection());
    if (fabs(denom) < 1e-6) // Rayon parallèle au plan
        return false;

    float t = dot(position - r.getOrigin(), normal) / denom;
    if (t < t_min || t > t_max)
        return false;

    Vec3 hit_point = r.point_at_parameter(t);
    float distance_squared = (hit_point - position).length_squared();
    if (distance_squared > radius * radius)
        return false;

    rec.t = t;
    rec.p = hit_point;
    rec.normal = normal;
    rec.mat_ptr = mat_ptr;
    return true;
}
