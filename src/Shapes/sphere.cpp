#include "sphere.hpp"

#include <cmath>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>

#include "Vec/Vec3.hpp"

sphere::sphere(const Setting &s)
{
    _position.setX(s["x"]);
    _position.setY(s["y"]);
    _position.setZ(s["z"]);
    _radius = s["r"];
    const Setting &color = s["color"];
    int r = color["r"];
    int g = color["g"];
    int b = color["b"];
    _color = sf::Color(r, g, b);
}


bool sphere::isIntersect(Ray &ray)
{
    Vec3 direction = {0, 0, 0};
    direction = direction.normalize(ray.getDirection());
    Vec3 origin = ray.getOrigin();
    float a = direction.dot(direction, direction);
    Vec3 OrigintoCenter = origin - _position;
    float b = 2.0f * direction.dot(direction, OrigintoCenter);
    float c = direction.dot(OrigintoCenter, OrigintoCenter) - (_radius * _radius);
    float delta = (b * b) - (4.0f * a * c);
    if (delta < 0)
        return false;
    if (delta == 0) {
        float t = -b / (2.0f * a);
        if (t > 0.001f) {
            ray.setDistance(t);
            return true;
        }
        return false;
    }
    float t0 = (-b + std::sqrt(delta)) / (2.0f * a);
    float t1 = (-b - std::sqrt(delta)) / (2.0f * a);
    if (t0 > 0.001f && t1 < 0.001f) {
        ray.setDistance(t1);
        return true;
    }
    if (t0 > 0.001f) {
        ray.setDistance(t0);
        return true;
    }
    return false;
}

Vec3 sphere::getNormal(Vec3 hitPoint)
{
    return hitPoint.normalize(hitPoint - _position);
}
