#pragma once
#include "LightFactory.hpp"
#include "ShapeFactory.hpp"
#include "Object/Object.hpp"

class Factory {
public:
    Factory() = default;
    ~Factory() = default;
    std::unique_ptr<Object> getObject(const std::string& name, const Setting &s);
    std::unique_ptr<ILights> getLight(const std::string &type, const Setting &s);
private:
    ShapeFactory _shapeFactory;
    LightFactory _lightFactory;
};
