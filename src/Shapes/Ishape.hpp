#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../Ray/Ray.hpp"
#include "../Vec/Vec2.hpp"

class IShapes {
public:
    virtual ~IShapes() = default;

    virtual bool isIntersect(Ray &ray) = 0;
    virtual void setPixel(Vec2 vec2, sf::Color color) = 0;
    virtual sf::Color getColor() = 0;
    virtual sf::Image getImage() = 0;
    virtual bool setTexture(sf::Image image) = 0;
    virtual void setSprite(sf::Texture texture) = 0;
    virtual sf::Texture getTexture() = 0;
    virtual sf::Sprite getSprite() = 0;
};
