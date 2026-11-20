#pragma once
#include <SFML/Graphics/Color.hpp>
#include "../Ray/Ray.hpp"
#include "../Material/Material.hpp"

class ILights {
public:
    virtual ~ILights() = default;
    ILights() = default;

    virtual sf::Color computeLight(Ray &ray, Material material, float closestT) = 0;
};
