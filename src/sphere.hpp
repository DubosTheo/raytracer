#pragma once
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector3.hpp>

#include "ray.hpp"

class sphere {
private:
    sf::Vector3f _position;
    float _radius;
    sf::Image _image;
    sf::Texture _texture;
    sf::Sprite _sprite;
public:
    sphere();
    void setPosition(sf::Vector3f position) {_position = position;}
    bool isIntersect(ray &ray);
    void setPixel(sf::Vector2u coords, sf::Color color);
    sf::Vector3f normalize(sf::Vector3f vector);
    float dot(sf::Vector3f vector1, sf::Vector3f vector2);
    sf::Image getImage() {return _image;}
    void setSprite(const sf::Texture &texture);
    sf::Texture &getTexture() {return _texture;}
    sf::Sprite getSprite() {return _sprite;}
};
