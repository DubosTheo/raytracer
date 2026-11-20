#pragma once
#include <libconfig.h++>

#include "ALights.hpp"

using namespace libconfig;

class Point : public ALights {
public:
    explicit Point(const Setting &s);
    sf::Color computeLight(Ray &ray, Material material, float closestT) override;
private:
};
