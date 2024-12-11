#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>

class Shape {
public:
    virtual ~Shape() {}
    virtual double getArea() const = 0;
    virtual std::string getType() const = 0;
    virtual void setDimensions(double d1, double d2 = 0) = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r = 0.0) : radius(r) {}
    double getArea() const override;
    std::string getType() const override;
    void setDimensions(double d1, double d2 = 0) override;
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w = 0.0, double h = 0.0) : width(w), height(h) {}
    double getArea() const override;
    std::string getType() const override;
    void setDimensions(double d1, double d2 = 0) override;
};

class Triangle : public Shape {
private:
    double base;
    double height;
public:
    Triangle(double b = 0.0, double h = 0.0) : base(b), height(h) {}
    double getArea() const override;
    std::string getType() const override;
    void setDimensions(double d1, double d2 = 0) override;
};

#endif
