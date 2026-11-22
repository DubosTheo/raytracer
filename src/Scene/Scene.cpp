#include "Scene.hpp"

#include <iostream>
#include <stdexcept>

void Scene::readCamera(const Setting &s)
{
    const Setting &c = s["camera"];

    _camera.setPos(c["position"]["x"], c["position.y"]["y"], c["position.z"]["z"]);
    _camera.setRotation(c["rotation"]["x"], c["rotation"]["y"], c["rotation"]["z"]);
    _camera.setFov(c["fov"]);
    _camera.setResX(c["resolution"]["width"]);
    _camera.setResY(c["resolution"]["height"]);
}


void Scene::readObjects(const Setting &s)
{
    const Setting &o = s["objects"];
    size_t size = o.getLength();

    for (size_t i = 0; i < size; i++) {
        const Setting &oTmp = o[static_cast<int>(i)];
        size_t sizeTmp = oTmp.getLength();
        std::string name = oTmp.getName();
        for (size_t j = 0; j < sizeTmp; j++) {
            _objects.push_back(_factory.getObject(name, oTmp[static_cast<int>(j)]));
        }
    }
}

void Scene::readLights(const Setting &s)
{
    _ambientLight = s["ambient"];
    const Setting &l = s["lights"];

    size_t size = l.getLength();
    for (size_t i = 0; i < size; i++) {
        const Setting &it = l[static_cast<int>(i)];
        std::string type = it["type"];
        _lights.push_back(_factory.getLight(type, it));
    }
}

Scene::Scene(std::string pathFile) : _camera()
{
    if (pathFile.empty())
        throw std::runtime_error("Invalid Pathfile\n");

    Config cfg;

    cfg.readFile(pathFile.data());
    const Setting &s = cfg.getRoot();

    readCamera(s);
    readLights(s);
    readObjects(s);
}
