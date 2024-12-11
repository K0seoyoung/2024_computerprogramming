#ifndef FURNITURE_H
#define FURNITURE_H

#include <string>
#include <iostream>

class Furniture {
private:
    std::string name;
    double x, y;       // position
    double rotation;   // angle in degrees
    double width, depth;

public:
    Furniture(const std::string& n="", double px=0, double py=0, double r=0, double w=0.5, double d=0.5)
    : name(n), x(px), y(py), rotation(r), width(w), depth(d) {}

    void setPosition(double px, double py);
    void setRotation(double r);
    void setDimensions(double w, double d);

    // 연산자 오버로딩: << 연산자 오버로드로 가구 정보 출력
    friend std::ostream& operator<<(std::ostream& os, const Furniture& f);

    // 가구 비교를 위해 == 연산자 오버로딩
    bool operator==(const Furniture& other) const {
        return (name == other.name && x == other.x && y == other.y && rotation == other.rotation);
    }
};

#endif
