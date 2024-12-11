#include "BuildingInfo.h"

BuildingInfo::BuildingInfo(Shape* s) : shape(s) {}

BuildingInfo::~BuildingInfo() {
    delete shape;
}

void BuildingInfo::addWindow(double x, double y) {
    windows.push_back({x,y});
}

void BuildingInfo::addDoor(double x, double y) {
    doors.push_back({x,y});
}

Shape* BuildingInfo::getShape() const {
    return shape;
}

const std::vector<std::pair<double,double>>& BuildingInfo::getWindows() const {
    return windows;
}

const std::vector<std::pair<double,double>>& BuildingInfo::getDoors() const {
    return doors;
}
