#include "Shape.h"
#include <cmath>

double Circle::getArea() const {
    return M_PI * radius * radius;
}

std::string Circle::getType() const {
    return "circle";
}

void Circle::setDimensions(double d1, double d2) {
    radius = d1;
}

double Rectangle::getArea() const {
    return width * height;
}

std::string Rectangle::getType() const {
    return "rectangle";
}

void Rectangle::setDimensions(double d1, double d2) {
    width = d1;
    height = d2;
}

double Triangle::getArea() const {
    return 0.5 * base * height;
}

std::string Triangle::getType() const {
    return "triangle";
}

void Triangle::setDimensions(double d1, double d2) {
    base = d1;
    height = d2;
}
