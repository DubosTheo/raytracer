#pragma once
#include <SFML/System/Vector3.hpp>
#include "sphere.hpp"
#include "ray.hpp"
class raytracer {
    ray _ray;
    sphere _sphere;
    bool _calcul = true;
public:
    raytracer();
    void run();
};
