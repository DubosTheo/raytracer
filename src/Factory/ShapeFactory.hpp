#pragma once
#include <functional>
#include <libconfig.h++>
#include <map>
#include <memory>
#include <string>

#include "../Shapes/Ishape.hpp"

using namespace libconfig;

class ShapeFactory {
public:
    ShapeFactory();
    std::unique_ptr<IShapes> getShape(const std::string &shape, const Setting &s);
private:
    std::map<std::string, std::function<std::unique_ptr<IShapes>(const Setting &s)>> _shapes;
};
