#pragma once
#include <libconfig.h++>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "../Camera/Camera.hpp"
#include "../Factory/Factory.hpp"
#include "../Object/Object.hpp"

using namespace libconfig;

class Scene {
public:
    explicit Scene(std::string pathfile);
    void readObjects(const Setting &s);
    void readCamera(const Setting &s);
    Camera getCamera() {return _camera;}
    std::vector<std::unique_ptr<Object>> getObject() {return std::move(_objects);}
private:
    std::vector<std::unique_ptr<Object>> _objects;
    Camera _camera;
    Factory _factory;
};
