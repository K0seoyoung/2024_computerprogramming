#ifndef CONSTRAINTS_H
#define CONSTRAINTS_H

#include <string>

class Constraints {
private:
    bool ensureFlow;
    std::string lightDirection; // e.g. "east", "west"
    std::string mandatoryFurnitureAlignment; // "sofa facing TV"

public:
    Constraints(bool flow=true, const std::string& ld="south", const std::string& m="sofa facing TV")
    : ensureFlow(flow), lightDirection(ld), mandatoryFurnitureAlignment(m) {}

    bool getEnsureFlow() const;
    std::string getLightDirection() const;
    std::string getMandatoryFurnitureAlignment() const;
};

#endif
