#pragma once
#include <libconfig.h++>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "AShapes.hpp"
#include "Ishape.hpp"
#include "../Vec/Vec2.hpp"
#include "../Vec/Vec3.hpp"

using namespace libconfig;

class sphere : public AShapes {
private:
    float _radius{};
    sf::Color _color;
public:
    explicit sphere(const Setting &s);
    sf::Color getColor() override {return _color;}
    bool isIntersect(Ray &ray) override;
    void setColor(sf::Color color) {_color = color;}
    Vec3 getNormal(Vec3 hitPoint) override;
};
