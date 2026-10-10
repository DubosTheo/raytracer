#include "raytracer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector3.hpp>
#include <cmath>
#include <vector>
#include <iostream>

sf::Vector3f raytracer::normalizeRay(sf::Vector3f ray)
{
    int lenght = sqrt({ray.x * ray.x, ray.y, ray.y, ray.z * ray.z});
    if (lenght == 0)
        return sf::Vector3f(0.0f, 0.0f, 0.0f);
    return sf::Vector3f(ray.x / lenght, ray.y / lenght, ray.z / lenght);
}


void raytracer::run()
{
    float height = 600;
    float width = 800;
    sf::RenderWindow window(sf::VideoMode({width, height}), "Raytracer");
    sf::Vector3f cameraPosition = {0.0f, 0.0f, -5.0f};

    while (window.isOpen()) {
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                while (const std::optional event = window.pollEvent())
                    if (event->is<sf::Event::Closed>())
                        window.close();
                float pixelX = (x + 0.5) / width * 2 - 1;
                float pixelY = ((y + 0.5) / height - 1) * 2;

                _ray =
            }
        }
    }
}
