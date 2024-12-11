#include "../headerFile/Furniture.h"

Furniture::Furniture(const std::string& n, double w, double h)
: name(n), x(0), y(0), rotation(0), width(w), height(h)
{}

void Furniture::print() const {
    std::cout << "Furniture: " << name 
              << " Pos(" << x << ", " << y << ") Rot(" << rotation << ")"
              << " Size(" << width << "x" << height << ")\n";
}

void Furniture::setPosition(double nx, double ny) {
    x = nx; y = ny;
}

void Furniture::setRotation(double r) {
    rotation = r;
}

bool Furniture::operator<(const Furniture& other) const {
    return (width * height) < (other.width * other.height);
}

bool Furniture::isPlacementValid(double roomWidth, double roomHeight) const {
    return (x >= 0 && x+width <= roomWidth && y >=0 && y+height <= roomHeight);
}
