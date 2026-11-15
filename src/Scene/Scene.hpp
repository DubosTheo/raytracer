#pragma once
#include <libconfig.h++>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "../Shapes/Ishape.hpp"
#include "Camera/Camera.hpp"
#include "Factory/ShapeFactory.hpp"
#include "Object/Object.hpp"

using namespace libconfig;


class Scene {
public:
    explicit Scene(std::string pathfile);
    static void readObjects(const Setting &s);
    void readCamera(const Setting &s);
private:
    std::vector<Object> _objects;
    Camera _camera;
    ShapeFactory _shapeFactory;
};
