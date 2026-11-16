#include "Vec3.hpp"

Vec3::Vec3(float x, float y, float z) : _x(x), _y(y), _z(z)
{}

Vec3 Vec3::operator-(const Vec3 &other) const
{
    return {_x - other._x, _y - other._y, _z - other._z};
}
