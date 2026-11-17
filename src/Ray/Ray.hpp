#pragma once
#include "../Vec/Vec3.hpp"

class Ray {
private:
    Vec3 _origin;
    Vec3 _direction;
    float _distance;
    int _indexShape = -1;
public:
    Ray();
    void setOrigin(Vec3 origin) {_origin = origin;}
    [[nodiscard]] Vec3 getOrigin() const {return _origin;}
    void setDirection(Vec3 direction){_direction = direction;}
    [[nodiscard]] Vec3 getDirection() const {return _direction;}
    void setDistance(float distance) {_distance = distance;}
    [[nodiscard]] float getDistance() const {return _distance;}
};
