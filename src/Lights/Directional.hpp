#pragma once

#include <libconfig.h++>

#include "ALights.hpp"

using namespace libconfig;

class Directional : public ALights{
public:
    Directional(const Setting &s);
    sf::Color computeLight(Ray &ray, Material material, float closestT) override;
private:
};
