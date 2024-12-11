#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual ~Shape() {}
    virtual double getArea() const = 0;
    virtual void printInfo() const = 0;
};

#endif
