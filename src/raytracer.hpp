#pragma once
#include <SFML/System/Vector3.hpp>
#include "Shapes/sphere.hpp"
#include "Camera.hpp"

class raytracer {
    Camera _camera;
    Ray _ray;
    bool _calcul = true;
public:
    raytracer();
    bool init();
    void run();
};
