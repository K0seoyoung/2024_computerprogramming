#ifndef OPTIMIZATIONALGORITHM_H
#define OPTIMIZATIONALGORITHM_H

class OptimizationAlgorithm {
public:
    virtual ~OptimizationAlgorithm() {}
    virtual void run() = 0;
};

#endif
