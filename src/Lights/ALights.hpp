#pragma once
#include "ILights.hpp"

class ALights : public ILights {
public:
    ALights();
    void setPosition(Vec3 position) override {_position = position;}
    Vec3 getPosition() override {return _position;}
    void setColor(sf::Color color) override {_color = color;}
    sf::Color getColor() override {return _color;}
    void setIntensity(float intensity) override {_intensity = intensity;}
    float getIntensity() override {return _intensity;}
protected:
    Vec3 _position;
    sf::Color _color;
    float _intensity = 0;
};
