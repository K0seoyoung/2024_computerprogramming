#include <iostream>
#include "CircleShape.h"

CircleShape::CircleShape(double r) : radius(r) {}

double CircleShape::getArea() const {
    return 3.141592 * radius * radius;
}

void CircleShape::printInfo() const {
    std::cout << "[Circle] radius: " << radius << ", area: " << getArea() << "\n";
}
