#include "Spot.hpp"

Spot::Spot(const Setting &s) : _direction(0, 0, 0)
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
    const Setting &d = s["direction"];
    _direction.setX(d["x"]);
    _direction.setY(d["y"]);
    _direction.setZ(d["y"]);
    _angle = s["angle"];
}

sf::Color Spot::computeLight(Ray &ray, Material material, float closestT)
{
}

