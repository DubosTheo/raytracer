#pragma once

#include <libconfig.h++>

#include "ALights.hpp"

using namespace libconfig;

class Directional : public ALights{
public:
    explicit Directional(const Setting &s);
    sf::Color computeLight(Ray &ray, Material material, float closestT) override;
    [[nodiscard]] Vec3 getDirection() const {return _direction;}
    void setDirection(Vec3 direction) {_direction = direction;}
private:
    Vec3 _direction;
};
