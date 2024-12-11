#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

#include "Shape.h"

class RectangleShape : public Shape {
private:
    double width, height;
public:
    RectangleShape(double w, double h);
    virtual double getArea() const override;
    virtual void printInfo() const override;
};

#endif
