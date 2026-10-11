#include "raytracer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector3.hpp>
#include <cmath>
#include <vector>
#include <iostream>


raytracer::raytracer()
{

}

void raytracer::run()
{
    float height = 600;
    float width = 800;
    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}), "Raytracer");
    float ar = width / height;
    float fovRadiant = (60 * (std::numbers::pi / 180)) / 2;
    float factor = std::tan(fovRadiant / 2);
    sf::Texture texture;
    if (!texture.resize({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}))
        return;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if (_calcul == true) {
            for (int x = 0; x < width; ++x) {
                for (int y = 0; y < height; ++y) {
                    float normX = (x + 0.5f) / width * 2 - 1;
                    float normY = 1 - ((y + 0.5) / height) * 2;
                    float aspectX = normX * ar;
                    float finalX = aspectX * factor;
                    float finalY = normY * factor;
                    _ray.setDirection(sf::Vector3f{finalX, finalY, -1});
                    if (_sphere.isIntersect(_ray)) {
                        sf::Vector2u coords{static_cast<unsigned int>(x), static_cast<unsigned int>(y)};
                        _sphere.setPixel(coords, sf::Color::Red);
                        std::cout << "passe\n";
                    }
                }
            }
            if (!_sphere.getTexture().loadFromImage(_sphere.getImage()))
                return;
            _sphere.setSprite(_sphere.getTexture());
            _calcul = false;
        }
        window.clear(sf::Color::Black);
        window.draw(_sphere.getSprite());
        window.display();
    }
}
