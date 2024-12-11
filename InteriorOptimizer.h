#ifndef INTERIOROPTIMIZER_H
#define INTERIOROPTIMIZER_H

#include <vector>
#include "Furniture.h"

// 추상 클래스
class InteriorOptimizer {
public:
    virtual ~InteriorOptimizer() {}
    virtual void optimize(std::vector<Furniture>& furnitures) = 0;
};

class GeneticOptimizer : public InteriorOptimizer {
public:
    void optimize(std::vector<Furniture>& furnitures) override;
};

class SimulatedAnnealingOptimizer : public InteriorOptimizer {
public:
    void optimize(std::vector<Furniture>& furnitures) override;
};

#endif
