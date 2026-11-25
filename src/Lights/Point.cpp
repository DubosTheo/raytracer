#include "Point.hpp"
#include <iostream>

Point::Point(const Setting &s)
{
    const Setting &p = s["position"];
    _position.setX(p["x"]);
    _position.setY(p["y"]);
    _position.setZ(p["z"]);
    const Setting &c = s["color"];
    int r = c["r"];
    int g = c["g"];
    int b = c["b"];
    _color = sf::Color(r, g, b);
    _intensity = s["intensity"];
}

sf::Color Point::computeLight(Ray &ray, Material material, float closestT)
{
    sf::Color color;
    return color;
}


