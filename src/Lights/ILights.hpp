#pragma once
#include <SFML/Graphics/Color.hpp>
#include "../Ray/Ray.hpp"
#include "../Material/Material.hpp"

class ILights {
public:
    virtual ~ILights() = default;
    ILights() = default;

    virtual sf::Color computeLight(Ray &ray, Material material, float closestT) = 0;
    virtual void setIntensity(float intensity) = 0;
    virtual float getIntensity() = 0;
    virtual void setPosition(Vec3 position) = 0;
    virtual Vec3 getPosition() = 0;
    virtual void setColor(sf::Color color) = 0;
    virtual sf::Color getColor() = 0;
};
