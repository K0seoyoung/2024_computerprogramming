#ifndef TABLE_H
#define TABLE_H

#include "Furniture.h"

class Table : public Furniture {
public:
    Table();
    virtual void print() const override;
};

#endif
