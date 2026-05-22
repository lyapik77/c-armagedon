#include "ExpressionEvaluator.h"
#include <cstring>

ExpressionEvaluator::ExpressionEvaluator() : count(20) {
    operands = new double[count]();
}

ExpressionEvaluator::ExpressionEvaluator(size_t n) : count(n) {
    operands = new double[count]();
}

ExpressionEvaluator::~ExpressionEvaluator() {
    delete[] operands;
}

void ExpressionEvaluator::setOperand(size_t pos, double value) {
    if (pos < count) operands[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], size_t n) {
    if (n > count) n = count;
    for (size_t i = 0; i < n; ++i) operands[i] = ops[i];
}

size_t ExpressionEvaluator::getCount() const { return count; }