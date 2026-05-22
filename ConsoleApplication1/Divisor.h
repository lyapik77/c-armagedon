#ifndef DIVISOR_H
#define DIVISOR_H

#include "ExpressionEvaluator.h"

class Divisor : public ExpressionEvaluator {
public:
    Divisor(size_t n);
    double calculate() const override;
    void logToScreen() const override;
    void logToFile(const std::string& filename) const override;
};

#endif