#pragma once

#include <libconfig.h++>

#include "ILights.hpp"

using namespace libconfig;

class Directional : public ILights{
public:
    Directional(const Setting &s);
    sf::Color computeLight(Ray &ray, Material material, float closestT) override;
private:
};
