#include "Render.hpp"

void Render::renderProperties(Ray &ray, Scene &scene, Material material, float closestT)
{
    Vec3 hitpoint = ray.getOrigin() + ray.getDirection() * closestT;

    const auto &objects = scene.getObject();
    const auto &lights = scene.getLights();

    Vec3 normal = objects[ray.getIndexObject()]->getShape().getNormal(hitpoint);
    Vec3 shadowOrigin = hitpoint + normal * 0.001f;
    float Tclosest = ray.getDistance();

    float ambiant = scene.getAmbientLight();

    for (const auto &itLights : lights) {
        if (!itLights)
            continue;
        Vec3 vectLight = itLights->getPosition() - shadowOrigin;
        float distLight = vectLight.getLenght(vectLight);
        Vec3 normLight = vectLight.normalize(vectLight);
        bool inShadow = false;
        for (const auto &itObj : objects) {
            if (!itObj)
                continue;
        }
    }
}
