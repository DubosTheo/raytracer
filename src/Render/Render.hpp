#pragma once
#include "../Ray/Ray.hpp"
#include "../Scene/Scene.hpp"

class Render {
public:
    Render() = default;
    ~Render() = default;
    void renderProperties(Ray &ray, Scene &scene, Material material, float closestT);
    sf::Color lightProperties(Ray &ray, Scene &scene, Material material, float closestT);
    void shadeProperties(Ray &ray, Scene &scene, Material material, float closestT);
};
