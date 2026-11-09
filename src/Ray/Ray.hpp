#pragma once
#include <SFML/System/Vector3.hpp>

class Ray {
private:
    sf::Vector3f _origin;
    sf::Vector3f _direction;
    sf::Vector3f _distance;
    int _indexShape = -1;
public:
    Ray();
    void setOrigin(sf::Vector3f origin) {_origin = origin;}
    [[nodiscard]] sf::Vector3f getOrigin() const {return _origin;}
    void setDirection(sf::Vector3f direction){_direction = direction;}
    [[nodiscard]] sf::Vector3f getDirection() const {return _direction;}
};
