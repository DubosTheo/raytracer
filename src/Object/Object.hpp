#pragma once
#include <memory>

#include "../Shapes/Ishape.hpp"
#include "Material/Material.hpp"

class Object {
public:
    Object() = default;
    ~Object() = default;
private:
    std::unique_ptr<IShapes> _shape;
    Material _material;
};
