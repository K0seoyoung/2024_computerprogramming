#include "UserPreferences.h"

void UserPreferences::setStyle(const std::string& s) {
    style = s;
}

void UserPreferences::setColorPalette(const std::string& c) {
    colorPalette = c;
}

void UserPreferences::setBudgetRange(double minB, double maxB) {
    budgetMin = minB;
    budgetMax = maxB;
}

void UserPreferences::addFurnitureType(const std::string& f) {
    furnitureList.push_back(f);
}

std::string UserPreferences::getStyle() const {
    return style;
}

std::string UserPreferences::getColorPalette() const {
    return colorPalette;
}

std::pair<double,double> UserPreferences::getBudgetRange() const {
    return {budgetMin, budgetMax};
}

const std::vector<std::string>& UserPreferences::getFurnitureList() const {
    return furnitureList;
}
