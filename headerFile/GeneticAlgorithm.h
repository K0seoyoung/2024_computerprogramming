#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include "OptimizationAlgorithm.h"

class GeneticAlgorithm : public OptimizationAlgorithm {
public:
    virtual void run() override;
};

#endif
