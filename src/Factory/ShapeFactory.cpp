#include "ShapeFactory.hpp"

#include "../Shapes/sphere.hpp"

ShapeFactory::ShapeFactory()
{
    _shapes["spheres"] = [](const Setting& s) {
        return std::make_unique<sphere>(s);
    };
}

std::unique_ptr<IShapes> ShapeFactory::getShape(const std::string &shape, const Setting &s)
{
    auto it = _shapes.find(shape);

    if (it != _shapes.end())
        return it->second(s);
    return nullptr;
}
