#include "LightFactory.hpp"

#include "../Lights/Point.hpp"
#include "Lights/Directional.hpp"
#include "Lights/Spot.hpp"

LightFactory::LightFactory()
{
    _lights["point"] = [](const Setting &s) {
        return std::make_unique<Point>(s);
    };
    _lights["directional"] = [](const Setting &s) {
        return std::make_unique<Directional>(s);
    };
    _lights["spot"] = [](const Setting &s) {
        return std::make_unique<Spot>(s);
    };
}

std::unique_ptr<ILights> LightFactory::getLight(const std::string &light, const Setting &s)
{
    auto it = _lights.find(light);

    if (it != _lights.end())
        return it->second(s);
    return nullptr;
}

