#pragma once
#include <cmath>

class Vec3 {
public:
    Vec3(float x, float y, float z);
    void setX(float x) {_x = x;}
    void setY(float y) {_y = y;}
    void setZ(float z) {_z = z;}
    [[nodiscard]] inline float getX() const {return _x;}
    [[nodiscard]] inline float getY() const {return _y;}
    [[nodiscard]] inline float getZ() const {return _z;}
    inline float getLenght(Vec3 vector) {return sqrt(vector.getX() * vector.getX() + vector.getY() * vector.getY() + vector.getZ() * vector.getZ());}
    inline Vec3 normalize(Vec3 vector) {    Vec3 vect(0, 0, 0);
        double lenght = std::sqrt(vector.getX() * vector.getX() + vector.getY() * vector.getY() + vector.getZ() * vector.getZ());
        if (lenght == 0)
            return vect;
        return Vec3(vector.getX() / lenght, vector.getY() / lenght, vector.getZ() / lenght);}
    inline float dot(Vec3 vector1, Vec3 vector2) {return vector1.getX() * vector2.getX() + vector1.getY() * vector2.getY() + vector1.getZ() * vector2.getZ();};
    inline Vec3 operator-(const Vec3 &other) const {return {_x - other._x, _y - other._y, _z - other._z};};
    inline Vec3 operator+(const Vec3 &other) const {return {_x + other._x, _y + other._y, _z + other._z};};
    inline Vec3 operator*(const Vec3 &other) const {return {_x * other._x, _y * other._y, _z * other._z};};
    inline Vec3 operator*(float nb) const {return {_x * nb, _y * nb, _z * nb};};
private:
    float _x = 0;
    float _y = 0;
    float _z = 0;
};
