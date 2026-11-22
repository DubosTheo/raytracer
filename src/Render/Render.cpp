#include "Render.hpp"

void Render::renderProperties(Ray &ray, Scene &scene, Material material, float closestT)
{
    Vec3 hitpoint = ray.getOrigin() + ray.getDirection() * closestT;
}
