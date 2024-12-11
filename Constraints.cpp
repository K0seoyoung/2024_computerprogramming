#include "Constraints.h"

bool Constraints::getEnsureFlow() const {
    return ensureFlow;
}

std::string Constraints::getLightDirection() const {
    return lightDirection;
}

std::string Constraints::getMandatoryFurnitureAlignment() const {
    return mandatoryFurnitureAlignment;
}
