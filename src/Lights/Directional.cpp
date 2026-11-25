#include "Directional.hpp"

Directional::Directional(const Setting &s) : _direction(0, 0, 0)
{
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
}

sf::Color Directional::computeLight(Ray &ray, Material material, float closestT)
{

}
