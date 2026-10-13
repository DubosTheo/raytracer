#pragma once

class Camera {
private:
    int _resX = 0;
    int _resY = 0;
    int _rotX = 0;
    int _rotY = 0;
    int _rotZ = 0;
    int _x = 0;
    int _y = 0;
    int _z = 0;
    double _fov = 110;
public:
    void setResX(const int resX) {_resX = resX;}
    [[nodiscard]] int getResX() const {return _resX;}
    void setResY(const int resY) {_resY = resY;}
    [[nodiscard]] int getResY() const {return _resY;}
    void setX(const int x) {_x = x;}
    [[nodiscard]] int getX() const {return _x;}
    void setY(const int y) {_y = y;}
    [[nodiscard]] int getY() const {return _y;}
    void setZ(const int z) {_z = z;}
    [[nodiscard]] int getZ() const {return _z;}
    void setFov(const int fov) {_fov = fov;}
    [[nodiscard]] double getFov() const {return _fov;}
    void setRotX(const int rotX) {_rotX = rotX;}
    [[nodiscard]] int getRotX() const {return _rotX;}
    void setRotY(const int rotY) {_rotY = rotY;}
    [[nodiscard]] int getRotY() const {return _rotY;}
    void setRotZ(const int rotZ) {_rotZ = rotZ;}
    [[nodiscard]] int getRotZ() const {return _rotZ;}
};
