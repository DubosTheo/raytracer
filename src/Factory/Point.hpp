#pragma once
#include "../Lights/ILights.hpp"

class Point : public ILights {
public:
    Point();
    ~Point();
    sf::Color computeLight(Ray &ray, Scene &scene, Material material, float closestT) override;
};
