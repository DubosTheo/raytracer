#pragma once
#include "ILights.hpp"

class ALights : public ILights {
public:
    ALights();
    void setPosition(Vec3 position) {_position = position;}
    [[nodiscard]] Vec3 getPosition() const {return _position;}
    void setColor(sf::Color color) {_color = color;}
    [[nodiscard]] sf::Color getColor() const {return _color;}
    void setIntensity(float intensity) {_intensity = intensity;}
    [[nodiscard]] float getIntensity() const {return _intensity;}
protected:
    Vec3 _position;
    sf::Color _color;
    float _intensity = 0;
};
