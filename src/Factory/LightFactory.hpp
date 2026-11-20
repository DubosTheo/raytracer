#pragma once
#include <functional>
#include <libconfig.h++>
#include <map>
#include <memory>
#include "../Lights/ILights.hpp"

using namespace libconfig;

class LightFactory {
public:
    LightFactory();
    ~LightFactory() = default;
    std::unique_ptr<ILights> getLight(const std::string &light, const Setting &s);
private:
    std::map<std::string, std::function<std::unique_ptr<ILights>(const Setting &s)>> _lights;
};
