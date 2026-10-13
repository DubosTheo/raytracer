#include "raytracer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector3.hpp>
#include <cmath>
#include <vector>
#include <libconfig.h++>
#include <iostream>

using namespace libconfig;

raytracer::raytracer() : _camera()
{
}

bool raytracer::init()
{
    Config cfg;

    try {
        cfg.readFile("scene.cfg");
    } catch(const FileIOException &fex) {
        std::cerr << "Erreur : Impossible de lire le fichier scene.cfg." << std::endl;
        return EXIT_FAILURE;
    } catch(const ParseException &pex) {
        std::cerr << "Erreur de syntaxe à la ligne " << pex.getLine() << " : " << pex.getError() << std::endl;
        return EXIT_FAILURE;
    }

    try {
        _camera.setResX(cfg.lookup("camera.resolution.width"));
        _camera.setResY(cfg.lookup("camera.resolution.height"));
        _camera.setX(cfg.lookup("camera.position.x"));
        _camera.setY(cfg.lookup("camera.position.y"));
        _camera.setZ(cfg.lookup("camera.position.z"));
        _camera.setRotX(cfg.lookup("camera.rotation.x"));
    } catch(const SettingNotFoundException &nfex) {
        std::cerr << "Erreur : Un paramètre est introuvable dans le fichier." << std::endl;
        return EXIT_FAILURE;
    } catch(const SettingTypeException &stex) {
        std::cerr << "Erreur : Mauvais type de données pour un paramètre." << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


void raytracer::run()
{
    std::cout << _camera.getResX() << std::endl;
    std::cout << _camera.getResY() << std::endl;
   // float height = 1080;
   // float width = 1920;
   // sf::RenderWindow window(sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}), "Raytracer");
   // float ar = width / height;
   // float fovRadiant = (60 * (std::numbers::pi / 180)) / 2;
   // float factor = std::tan(fovRadiant / 2);
   // sf::Texture texture;
   // if (!texture.resize({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}))
   //     return;
//
   // while (window.isOpen()) {
   //     while (const std::optional event = window.pollEvent()) {
   //         if (event->is<sf::Event::Closed>())
   //             window.close();
   //     }
   //     window.clear(sf::Color::Black);
   //     if (_calcul == true) {
   //         for (int x = 0; x < width; ++x) {
   //             for (int y = 0; y < height; ++y) {
   //                 float normX = (x + 0.5f) / width * 2 - 1;
   //                 float normY = 1 - ((y + 0.5) / height) * 2;
   //                 float aspectX = normX * ar;
   //                 float finalX = aspectX * factor;
   //                 float finalY = normY * factor;
   //                 _ray.setDirection(sf::Vector3f{finalX, finalY, -1});
   //                 if (_sphere.isIntersect(_ray)) {
   //                     sf::Vector2u coords{static_cast<unsigned int>(x), static_cast<unsigned int>(y)};
   //                     _sphere.setPixel(coords, sf::Color::Red);
   //                 }
   //             }
   //         }
   //         if (!_sphere.getTexture().loadFromImage(_sphere.getImage()))
   //             return;
   //         _sphere.setSprite(_sphere.getTexture());
   //         _calcul = false;
   //     }
   //     window.draw(_sphere.getSprite());
   //     window.display();
   // }
}
