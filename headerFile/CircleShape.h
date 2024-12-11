#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "Shape.h"

class CircleShape : public Shape {
private:
    double radius;
public:
    CircleShape(double r);
    virtual double getArea() const override;
    virtual void printInfo() const override;
};

#endif
