/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** Lambertian
*/

#include "Lambertian.hpp"
#include "SingletonLogger.hpp"

Lambertian::Lambertian(const Vec3 &a) : albedo(a)
{
    Logger *logger = LoggerSingleton::getInstance();
	std::ostringstream msg;
    msg << "LOG: Lambertian created with a = " << a << ".";
	logger->log(INFO, msg.str());
}

Lambertian::~Lambertian()
{
}
//rajouter light + objs

bool Lambertian::hit(const Ray& r, float t_min, float t_max, hit_record_t& rec, const std::vector<std::shared_ptr<IHitable>>& _world) const {
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

bool Lambertian::scatter(const Ray& r_in, const hit_record_t &rec, Vec3& attenuation, Ray& scattered, Light light, const std::vector<std::shared_ptr<IHitable>>& _obj) const
{
    if (!light.isDirec()) {
        Vec3 lightDir = light.calculateLightDirection(rec.p);
        float cos_theta = fabs(dot(rec.normal, lightDir));
        Vec3 shadowRayOrigin = rec.p; // Déplace légèrement le point pour éviter l'auto-ombrage edit: c'est deja fait
        Vec3 shadowRayDirection = light.getPosition() - rec.p;
        Ray shadowRay(shadowRayOrigin, shadowRayDirection);
        hit_record_t shadowRec;
        if (hit(shadowRay, 0.001, MAXFLOAT, shadowRec, _obj)) {
            // Le point est dans l'ombr
            float distanceToLight = (light.getPosition() - rec.p).length();
            float attenuationFactor = 1 / (1 + distanceToLight); // Plus le point est éloigné de la source lumineuse, plus il s'assombrit
            attenuation = albedo * light.getIntensity() * cos_theta * attenuationFactor;
            return false;
        }
        
        // Le point peut voir la lumière directement
        scattered = Ray(rec.p, rec.normal + random_in_unit_sphere());
        attenuation = albedo * light.getIntensity() * cos_theta;
        return true;
    } else {
        Vec3 lightDir = light.getNormal(); // Direction de la lumière perpendiculaire au plan
        lightDir.make_unit_vector(); // Normalisation de la direction de la lumière
        Vec3 lightPos = light.getPosition();

        // Vérification de l'angle entre la normale de la surface et la direction de la lumière
        float cos_theta = dot(rec.normal, lightDir);
        Vec3 pointToLight = lightPos - rec.p;

        // Si le produit scalaire entre le vecteur du point à la lumière et la normale de la lumière est négatif,
        // cela signifie que le point est au-dessus du plan lumineux par rapport à sa normale, donc il est éclairé
        if (dot(pointToLight, light.getNormal()) > 0 && cos_theta > 0) {
            // Construction du rayon entre le point à évaluer et le point perpendiculaire au plan de lumière
            Vec3 shadowRayOrigin = rec.p;
            Vec3 shadowRayDirection = lightDir;
            Ray shadowRay(shadowRayOrigin, shadowRayDirection);

            // Ajout d'une marge d'erreur pour éviter que tout ne soit sombre
            float epsilon = 0.001;

            // Vérification de l'intersection entre le rayon et les objets de la scène
            hit_record_t shadowRec;
            if (hit(shadowRay, epsilon, MAXFLOAT, shadowRec, _obj)) {
                // Le point est dans l'ombre
                attenuation = Vec3(0, 0, 0);
                return false;
            }
            else {
                // Le point peut voir la lumière directement
                scattered = Ray(rec.p, rec.normal + random_in_unit_sphere());
                attenuation = albedo * light.getIntensity() * cos_theta;
                return true;
            }
        }
        else {
            // Le point est en dessous du plan lumineux par rapport à sa normale
            // Il est dans l'ombre
            attenuation = Vec3(0, 0, 0);
            return false;
        }
    }
}
