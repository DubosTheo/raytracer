#pragma once
#include <libconfig.h++>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "../Camera/Camera.hpp"
#include "../Factory/Factory.hpp"
#include "../Object/Object.hpp"
#include "../Lights/ILights.hpp"

using namespace libconfig;

class Scene {
public:
    explicit Scene(std::string pathfile);
    void readLights(const Setting &s);
    void readObjects(const Setting &s);
    void readCamera(const Setting &s);
    [[nodiscard]] Camera getCamera() const {return _camera;}
    sf::Image &getImage() {return _frameBuffer;}
    std::vector<std::unique_ptr<Object>> getObject() {return std::move(_objects);}
    std::vector<std::unique_ptr<ILights>> getLights() {return std::move(_lights);}
private:
    std::vector<std::unique_ptr<Object>> _objects;
    std::vector<std::unique_ptr<ILights>> _lights;
    Camera _camera;
    Factory _factory;
    sf::Image _frameBuffer;
    float _ambientLight = 0;
};
