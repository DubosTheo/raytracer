#include "raytracer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector3.hpp>
#include <cmath>
#include <utility>
#include <vector>
#include <libconfig.h++>
#include <iostream>

using namespace libconfig;

raytracer::raytracer(std::string pathfile) : _scene(std::move(pathfile))
{
}

bool raytracer::init()
{
    return true;
}


void raytracer::run()
{
    int width = _scene.getCamera().getResX();
    int height = _scene.getCamera().getResY();
    std::vector<std::unique_ptr<Object>> objects = _scene.getObject();
    Ray ray;
    ray.setOrigin(_scene.getCamera().getPos());
    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}), "Raytracer");
    sf::Image screenImage;
    screenImage.resize({static_cast<unsigned int>(width), static_cast<unsigned int>(height)});
    sf::Texture screenTexture;
    sf::Sprite screenSprite(screenTexture);
    float ar = static_cast<float>(width) / static_cast<float>(height);
    float fovDegrees = 60.0f;
    float fovRadiant = (fovDegrees * std::numbers::pi / 180.0f);
    float factor = std::tan(fovRadiant / 2.0f);

   while (window.isOpen()) {
       while (const std::optional event = window.pollEvent()) {
           if (event->is<sf::Event::Closed>())
               window.close();
       }
       if (_calcul == true) {
           for (unsigned int x = 0; x < width; ++x) {
               for (unsigned int y = 0; y < height; ++y) {
                   screenImage.setPixel({x, y}, sf::Color::Black);
               }
           }
           for (int x = 0; x < width; ++x) {
               for (int y = 0; y < height; ++y) {
                   float normX = (x + 0.5f) / static_cast<float>(width) * 2.0f - 1.0f;
                   float normY = 1.0f - ((y + 0.5f) / static_cast<float>(height)) * 2.0f;
                   float aspectX = normX * ar;
                   float finalX = aspectX * factor;
                   float finalY = normY * factor;
                   ray.setDirection(Vec3{finalX, finalY, 1});
                   for (const auto &it : objects) {
                       if (it->getShape().isIntersect(ray)) {
                           screenImage.setPixel({static_cast<unsigned int>(x), static_cast<unsigned int>(y)}, it->getShape().getColor());
                       }
                   }
               }
           }
           if (!screenTexture.loadFromImage(screenImage))
               throw std::runtime_error("Can't load screen texture\n");
           screenSprite.setTexture(screenTexture, true);
           _calcul = false;
       }
       window.clear(sf::Color::Black);
       window.draw(screenSprite);
       window.display();
   }
}
