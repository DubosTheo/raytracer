#include "Factory.hpp"

std::unique_ptr<Object> Factory::getObject(const std::string& name, const Setting &s)
{
    auto object = std::make_unique<Object>();

    object->setShape(_shapeFactory.getShape(name, s));
    return object;
}
