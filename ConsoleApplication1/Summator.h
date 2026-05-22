#pragma once
#ifndef SUMMATOR_H
#define SUMMATOR_H

#include "ExpressionEvaluator.h"

class Summator : public ExpressionEvaluator {
public:
    Summator(size_t n);
    double calculate() const override;
    void logToScreen() const override;
    void logToFile(const std::string& filename) const override;
};

#endif