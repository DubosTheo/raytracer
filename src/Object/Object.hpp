#pragma once
#include <memory>

#include "../Shapes/Ishape.hpp"
#include "../Material/Material.hpp"
class Object {
public:
    Object() = default;
    ~Object() = default;
    void setShape(std::unique_ptr<IShapes> shape) {_shape = std::move(shape);}
    [[nodiscard]] IShapes &getShape() const {return *_shape;}
    void setMaterial(const Material material) {_material = material;}
    [[nodiscard]] Material getMaterial() const {return  _material;}
private:
    std::unique_ptr<IShapes> _shape;
    Material _material;
};
