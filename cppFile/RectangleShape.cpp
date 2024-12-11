#include <iostream>
#include "../headerFile/RectangleShape.h"

RectangleShape::RectangleShape(double w, double h) : width(w), height(h) {}

double RectangleShape::getArea() const {
    return width * height;
}

void RectangleShape::printInfo() const {
    std::cout << "[Rectangle] width: " << width << ", height: " << height
              << ", area: " << getArea() << "\n";
}
