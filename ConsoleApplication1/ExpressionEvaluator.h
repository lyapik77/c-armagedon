#pragma once
#ifndef EXPRESSIONEVALUATOR_H
#define EXPRESSIONEVALUATOR_H

#include <string>
#include "ILoggable.h"

class ExpressionEvaluator : public ILoggable {
protected:
    double* operands;
    size_t count;

public:
    ExpressionEvaluator();
    ExpressionEvaluator(size_t n);
    virtual ~ExpressionEvaluator();

    void setOperand(size_t pos, double value);
    void setOperands(double ops[], size_t n);
    size_t getCount() const;

    virtual double calculate() const = 0;
};

#endif