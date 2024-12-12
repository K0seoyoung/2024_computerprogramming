#ifndef BUILDINGINFO_H
#define BUILDINGINFO_H

#include "Shape.h"
#include <vector>
#include <utility>

class BuildingInfo {
private:
    Shape* shape;
    std::vector<std::pair<double,double> > windows; // (x,y)
    std::vector<std::pair<double,double> > doors;   // (x,y)

public:
    BuildingInfo(Shape* s = nullptr);
    ~BuildingInfo();
    void addWindow(double x, double y);
    void addDoor(double x, double y);
    Shape* getShape() const;
    const std::vector<std::pair<double,double> >& getWindows() const;
    const std::vector<std::pair<double,double> >& getDoors() const;
};

#endif
