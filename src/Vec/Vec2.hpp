#pragma once

class Vec2 {
public:
    Vec2() = default;
    ~Vec2() = default;
    void setX(const float x) {_x = x;}
    float getX() const {return _x;}
    void setY(const float y) {_y = y;}
    float getY() const {return _y;}
private:
    float _x;
    float _y;
};
