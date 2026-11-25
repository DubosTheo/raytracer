#pragma once
#include <libconfig.h++>

#include "ALights.hpp"
#include "../Shapes/Ishape.hpp"

using namespace libconfig;

class Spot : public ALights {
public:
    Spot(const Setting &s);
    sf::Color computeLight(Ray &ray, Material material, float closestT) override;
    [[nodiscard]] Vec3 getDirection() const {return _direction;}
    void setDirection(Vec3 direction) {_direction = direction;}
    [[nodiscard]] float getAngle() const {return _angle;}
    void setAngle(float angle) {_angle = angle;}
private:
    Vec3 _direction;
    float _angle;
};
