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
    virtual sf::Color getColor() = 0;
    virtual Vec3 getNormal(Vec3 hitPoint) = 0;
};
