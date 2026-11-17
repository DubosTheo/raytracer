#include "sphere.hpp"

#include <cmath>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>

#include "Vec/Vec3.hpp"

sphere::sphere(const Setting &s) : _position(0, 0, 0), _sprite(_texture)
{
    _position.setX(s["x"]);
    _position.setY(s["y"]);
    _position.setZ(s["z"]);
    _radius = s["r"];
    const Setting &color = s["color"];
    int r = color["r"];
    int g = color["g"];
    int b = color["b"];
    _color = sf::Color::Red;
    _image.resize({800, 600});
}


Vec3 sphere::normalize(Vec3 vector)
{
    Vec3 vect(0, 0, 0);
    double lenght = std::sqrt(vector.getX() * vector.getX() + vector.getY() * vector.getY() + vector.getZ() * vector.getZ());
    if (lenght == 0)
        return vect;
    return Vec3(vector.getX() / lenght, vector.getY() / lenght, vector.getZ() / lenght);
}

float sphere::dot(Vec3 vector1, Vec3 vector2)
{
    return vector1.getX() * vector2.getX() + vector1.getY() * vector2.getY() + vector1.getZ() * vector2.getZ();
}


bool sphere::isIntersect(Ray &ray)
{
    Vec3 direction = normalize(ray.getDirection());
    Vec3 origin = ray.getOrigin();
    float a = dot(direction, direction);
    Vec3 OrigintoCenter = origin - _position;
    float b = 2 * dot(direction, OrigintoCenter);
    float c = dot(OrigintoCenter, OrigintoCenter) - _radius * _radius;
    float delta = b * b - (4 * a * c);
    if (delta < 0)
        return false;
    if (delta == 0) {
        float t = -(b / (2 * a));
        if (t > 0.001f)
            return true;
        return false;
    }
    float t0 = (-b + sqrt(delta)) / (2 * a);
    float t1 = (-b - sqrt(delta)) / (2 * a);
    if (t0 > 0.001f || t1 > 0.001f)
        return true;
    return false;
}

void sphere::setSprite(const sf::Texture &texture)
{
    _sprite.setTexture(texture,true);
}


void sphere::setPixel(Vec2 coords, sf::Color color)
{
    _image.setPixel({static_cast<unsigned int>(coords.getX()), static_cast<unsigned int>(coords.getY())}, color);
}

void sphere::setSprite(sf::Texture texture)
{
    _sprite.setTexture(texture);
}

bool sphere::setTexture(sf::Image image)
{
    return _texture.loadFromImage(image);
}

