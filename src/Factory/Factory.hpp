#pragma once
#include "ShapeFactory.hpp"
#include "Object/Object.hpp"

class Factory {
public:
    Factory() = default;
    ~Factory() = default;
    std::unique_ptr<Object> getObject(const std::string& name, const Setting &s);
private:
    ShapeFactory _shapeFactory;
};
