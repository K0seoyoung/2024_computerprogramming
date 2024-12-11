#ifndef SIMULATEDANNEALING_H
#define SIMULATEDANNEALING_H

#include "OptimizationAlgorithm.h"

class SimulatedAnnealing : public OptimizationAlgorithm {
public:
    virtual void run() override;
};

#endif
