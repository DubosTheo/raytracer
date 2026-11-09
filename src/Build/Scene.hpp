#pragma once
#include <libconfig.h++>
#include <memory>
#include <string>
#include <vector>

#include "../Shapes/Ishape.hpp"

using namespace libconfig;

class Scene {
private:
    std::vector<std::unique_ptr<IShapes>> _shapes;
public:
    Scene(std::string string);
    void readPrimitives(const Setting &s);
};
