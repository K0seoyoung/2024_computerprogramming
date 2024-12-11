#include "Table.h"
#include <iostream>

Table::Table() : Furniture("Table", 1.5, 1.5) {}

void Table::print() const {
    std::cout << "[Table]: ";
    Furniture::print();
}
