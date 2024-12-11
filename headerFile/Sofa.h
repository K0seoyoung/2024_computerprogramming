#ifndef SOFA_H
#define SOFA_H

#include "Furniture.h"

class Sofa : public Furniture {
public:
    Sofa();
    virtual void print() const override;
};

#endif
