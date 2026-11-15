#pragma once

class Vec3 {
public:
    void setX(float x) {_x = x;}
    void setY(float y) {_y = y;}
    void setZ(float z) {_z = z;}
    [[nodiscard]] float getX() const {return _x;}
    [[nodiscard]] float getY() const {return _y;}
    [[nodiscard]] float getZ() const {return _z;}
private:
    float _x = 0;
    float _y = 0;
    float _z = 0;
};
