#pragma once
#include <libconfig.h++>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Ishape.hpp"
#include "../Vec/Vec2.hpp"
#include "../Vec/Vec3.hpp"

using namespace libconfig;

class sphere : public IShapes {
private:
    Vec3 _position;
    float _radius{};
    sf::Image _image;
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Color _color;
public:
    explicit sphere(const Setting &s);
    sf::Color getColor() override {return _color;}
    void setPosition(Vec3 position) {_position = position;}
    bool isIntersect(Ray &ray) override;
    void setPixel(Vec2, sf::Color) override;
    Vec3 normalize(Vec3 vector);
    float dot(Vec3 vector1, Vec3 vector2);
    sf::Image getImage() override {return _image;}
    void setSprite(const sf::Texture &texture);
    sf::Texture getTexture() override {return _texture;}
    sf::Sprite getSprite() override {return _sprite;}
    void setColor(sf::Color color) {_color = color;}
    void setSprite(sf::Texture texture) override;
    bool setTexture(sf::Image image) override;
};
