#ifndef FURNITURE_H
#define FURNITURE_H

#include <string>
#include <iostream>

class Furniture {
protected:
    std::string name;
    double x, y;    
    double rotation; 
    double width, height; 
public:
    Furniture(const std::string& n, double w, double h);
    virtual ~Furniture() {}
    virtual void print() const;
    void setPosition(double nx, double ny);
    void setRotation(double r);

    bool operator<(const Furniture& other) const;
    virtual bool isPlacementValid(double roomWidth, double roomHeight) const;
};

#endif
