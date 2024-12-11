#include "Sofa.h"
#include <iostream>

Sofa::Sofa() : Furniture("Sofa", 2.0, 1.0) {}

void Sofa::print() const {
    std::cout << "[Sofa]: ";
    Furniture::print();
}
