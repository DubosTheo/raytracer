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

                    //set ray
                    float normX = (x + 0.5f) / static_cast<float>(width) * 2.0f - 1.0f;
                    float normY = 1.0f - ((y + 0.5f) / static_cast<float>(height)) * 2.0f;
                    float aspectX = normX * ar;
                    float finalX = aspectX * factor;
                    float finalY = normY * factor;
                    bool isHit = false;
                    sf::Color finalColor = sf::Color::Black;
                    ray.setDirection(Vec3{finalX, finalY, 1});
                    ray.setDistance(0);
                    float closestT = std::numeric_limits<float>::max();

                    //find closest ray
                    for (const auto &it : objects) {
                        if (it->getShape().isIntersect(ray)) {
                            if (ray.getDistance() < closestT) {
                                isHit = true;
                                closestT = ray.getDistance();
                                finalColor = it->getShape().getColor();
                            }
                        }
                    }
                    if (isHit)
                        screenImage.setPixel({static_cast<unsigned int>(x), static_cast<unsigned int>(y)}, finalColor);
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
