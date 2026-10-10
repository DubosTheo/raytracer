#pragma once
#include <SFML/System/Vector3.hpp>
#include "sphere.hpp"
#include "ray.hpp"
class raytracer {
    ray _ray;
    sphere _sphere;
public:
    void run();
    sf::Vector3f normalizeRay(sf::Vector3f ray);
};
