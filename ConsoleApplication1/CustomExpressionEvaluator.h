#pragma once
#ifndef CUSTOMEXPRESSIONEVALUATOR_H
#define CUSTOMEXPRESSIONEVALUATOR_H

#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle {
public:
    CustomExpressionEvaluator(size_t n);
    double calculate() const override;
    void logToScreen() const override;
    void logToFile(const std::string& filename) const override;

    void shuffle() override;
    void shuffle(size_t i, size_t j) override;
};

#endif