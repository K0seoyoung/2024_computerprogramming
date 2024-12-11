#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class BudgetExceededException : public std::runtime_error {
public:
    BudgetExceededException(const std::string& msg) : std::runtime_error(msg) {}
};

class InvalidPlacementException : public std::runtime_error {
public:
    InvalidPlacementException(const std::string& msg) : std::runtime_error(msg) {}
};

#endif
