#pragma once
#include <SFML/System/Vector3.hpp>
#include "sphere.hpp"
#include "ray.hpp"
#include "Camera.hpp"

class raytracer {
    Camera _camera;
    ray _ray;
    sphere _sphere;
    bool _calcul = true;
public:
    raytracer();
    bool init();
    void run();
};
