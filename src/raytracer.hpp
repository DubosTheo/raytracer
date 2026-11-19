#pragma once
#include <SFML/System/Vector3.hpp>
#include "Shapes/sphere.hpp"
#include "Camera/Camera.hpp"
#include "Render/Render.hpp"
#include "Scene/Scene.hpp"

class raytracer {
    Scene _scene;
    Render _render;
    bool _calcul = true;
public:
    explicit raytracer(std::string pathfile);
    bool init();
    void run();
};
