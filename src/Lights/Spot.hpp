#pragma once
#include <libconfig.h++>

#include "ILights.hpp"
#include "../Shapes/Ishape.hpp"

using namespace libconfig;

class Spot : public ILights {
public:
    Spot(const Setting &s);
    sf::Color computeLight(Ray &ray, Material material, float closestT) override;
private:
};
