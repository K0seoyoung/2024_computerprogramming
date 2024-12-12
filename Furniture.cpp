#include "Furniture.h"

void Furniture::setPosition(double px, double py) {
    x = px; 
    y = py;
}

void Furniture::setRotation(double r) {
    rotation = r;
}

void Furniture::setDimensions(double w, double d) {
    width = w;
    depth = d;
}

std::ostream& operator<<(std::ostream& os, const Furniture& f) {
    os << "Furniture: " << f.name 
       << " Position(" << f.x << "," << f.y << ") "
       << "Rotation: " << f.rotation << "deg "
       << "Size(" << f.width << "x" << f.depth << ")";
    return os;
}
