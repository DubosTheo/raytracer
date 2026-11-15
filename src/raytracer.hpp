#pragma once
#include <SFML/System/Vector3.hpp>
#include "Shapes/sphere.hpp"
#include "Camera/Camera.hpp"
#include "Scene/Scene.hpp"

class raytracer {
    Scene _scene;
    bool _calcul = true;
public:
    explicit raytracer(std::string pathfile);
    bool init();
    void run();
};
