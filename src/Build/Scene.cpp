#include "Scene.hpp"

#include <stdexcept>

void Scene::readPrimitives(const Setting &s)
{

}

Scene::Scene(std::string pathFile)
{
    if (pathFile.empty())
        throw std::runtime_error("Invalid Pathfile\n");

    Config cfg;

    cfg.readFile(pathFile.data());
    const Setting &s = cfg.getRoot();

    readPrimitives(s);
}
