#pragma once
#include <libconfig.h++>
#include <memory>
#include "../Lights/ILights.hpp"

using namespace libconfig;

class LightFactory {
public:
    LightFactory();
    ~LightFactory() = default;
    std::unique_ptr<ILights> getLight(const std::string &light, const Setting &s);
private:
};
