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
       window.clear(sf::Color::Black);
       if (_calcul == true) {
           for (int x = 0; x < width; ++x) {
               for (int y = 0; y < height; ++y) {
                   float normX = (x + 0.5f) / static_cast<float>(width) * 2 - 1;
                   float normY = 1 - ((y + 0.5) / height) * 2;
                   float aspectX = normX * ar;
                   float finalX = aspectX * factor;
                   float finalY = normY * factor;
                   ray.setDirection(Vec3{finalX, finalY, -1});
                   for (const auto &it :objects) {
                       if (it->getShape().isIntersect(ray)) {
                           Vec2 coords(static_cast<float>(x), static_cast<float>(y));
                           it->getShape().setPixel(coords, it->getShape().getColor());
                       }
                   }
               }
           }
           for (const auto &it : objects) {
               if (!it->getShape().setTexture(it->getShape().getImage()))
                   throw std::runtime_error("Can't set Texture\n");
               it->getShape().setSprite(it->getShape().getTexture());
           }
           _calcul = false;
       }
       for (const auto &it : objects) {
           window.draw(it->getShape().getSprite());
           window.display();
       }
   }
}
