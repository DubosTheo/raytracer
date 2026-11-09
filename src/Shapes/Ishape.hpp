#pragma once
#include "../Ray/Ray.hpp"

class IShapes {
public:
    virtual ~IShapes() = default;

    IShapes() = default;
    virtual bool isIntersect(Ray &ray) = 0;
};
