#pragma once
#include "Vec/Vec3.hpp"

class Camera {
private:
    unsigned int _resX = 0;
    unsigned int _resY = 0;
    Vec3 _rotation;
    Vec3 _pos;
    double _fov = 110;
public:
    void setResX(const unsigned int resX) {_resX = resX;}
    [[nodiscard]] unsigned int getResX() const {return _resX;}
    void setResY(const unsigned int resY) {_resY = resY;}
    [[nodiscard]] unsigned int getResY() const {return _resY;}
    void setPos(float x, float y, float z) {_pos.setX(x); _pos.setY(y); _pos.setZ(z);}
    [[nodiscard]] Vec3 getPos() const {return _pos;}
    void setFov(const int fov) {_fov = fov;}
    [[nodiscard]] double getFov() const {return _fov;}
    void setRotation(float x, float y, float z) {_rotation.setX(x); _rotation.setY(y); _rotation.setZ(z);}
    [[nodiscard]] Vec3 getRotation() const {return _rotation;}
};
