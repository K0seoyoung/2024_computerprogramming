#ifndef INTERIORDESIGNASSISTANT_H
#define INTERIORDESIGNASSISTANT_H

#include <memory>
#include "Shape.h"
#include "FurnitureList.h"
#include "Furniture.h"
#include "Style.h"
#include "OptimizationAlgorithm.h"
#include "Exceptions.h"

class InteriorDesignAssistant {
private:
    std::unique_ptr<Shape> buildingShape;
    Style style;
    double budget;
    FurnitureList<Furniture> furnitures;
    std::unique_ptr<OptimizationAlgorithm> optimizer;

    double roomWidth;
    double roomHeight;

public:
    InteriorDesignAssistant(std::unique_ptr<Shape> shape, const Style& s, double b);
    void setAlgorithm(OptimizationAlgorithm* alg);
    void addFurniture(Furniture* f);
    void arrangeFurniture();
    void printResult() const;
};

#endif
