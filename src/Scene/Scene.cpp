#include "Scene.hpp"

#include <iostream>
#include <stdexcept>

void Scene::readCamera(const Setting &s)
{
    const Setting &c = s["camera"];

    std::cout << "passe" << std::endl;
    _camera.setPos(c["position"]["x"], c["position.y"]["y"], c["position.z"]["z"]);
    Vec3 pos = _camera.getPos();
    std::cout << "pos x : " << pos.getX() << ", pos y : " << pos.getY() << ", pos z : " << pos.getZ();
}


void Scene::readObjects(const Setting &s)
{
    const Setting &o = s["objects"];
    size_t size = o.getLength();

    for (size_t i = 0; i < size; i++) {
    }
}

Scene::Scene(std::string pathFile)
{
    if (pathFile.empty())
        throw std::runtime_error("Invalid Pathfile\n");

    Config cfg;

    cfg.readFile(pathFile.data());
    const Setting &s = cfg.getRoot();

    readCamera(s);
    readObjects(s);
}
