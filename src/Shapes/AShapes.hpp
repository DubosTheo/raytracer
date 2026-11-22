#pragma once
#include "Ishape.hpp"

class AShapes : public IShapes{
public:
    AShapes();
    [[nodiscard]] Vec3 getPosition() const {return _position;}
    void setPosition(Vec3 position) {_position = position;}
protected:
    Vec3 _position;
};
