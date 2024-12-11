#include <iostream>
#include "Style.h"

Style::Style(const std::string& c, const std::string& m)
: colorPalette(c), material(m) {}

void Style::print() const {
    std::cout << "Style: Color=" << colorPalette << ", Material=" << material << "\n";
}
