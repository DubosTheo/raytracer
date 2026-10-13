#include "sphere.hpp"

#include <cmath>
#include <SFML/Graphics/Texture.hpp>

sphere::sphere() : _position({-2.0f, 0.0f, -50.0f}), _radius(3), _sprite(_texture)
{
    _image.resize({800, 600});
}


sf::Vector3f sphere::normalize(sf::Vector3f vector)
{
    double lenght = std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    if (lenght == 0)
        return sf::Vector3f(0.0f, 0.0f, 0.0f);
    return sf::Vector3f(vector.x / lenght, vector.y / lenght, vector.z / lenght);
}

float sphere::dot(sf::Vector3f vector1, sf::Vector3f vector2)
{
    return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}


bool sphere::isIntersect(ray &ray)
{
    sf::Vector3f direction = normalize(ray.getDirection());
    sf::Vector3f origin = ray.getOrigin();
    float a = dot(direction, direction);
    sf::Vector3f OrigintoCenter = origin - _position;
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


void sphere::setPixel(sf::Vector2u coords, sf::Color color)
{
    _image.setPixel(coords, color);
}
