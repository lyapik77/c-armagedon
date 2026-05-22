#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <fstream>
#include <algorithm>

CustomExpressionEvaluator::CustomExpressionEvaluator(size_t n) : ExpressionEvaluator(n) {}

double CustomExpressionEvaluator::calculate() const {
    // result = x1 - x2 + x3 - x4 + ...
    double res = 0;
    for (size_t i = 0; i < count; ++i) {
        if (i % 2 == 0) res += operands[i];
        else res -= operands[i];
    }
    return res;
}

void CustomExpressionEvaluator::logToScreen() const {
    std::cout << "[ " << count << " ]\n";
    for (size_t i = 0; i < count; ++i) {
        if (operands[i] < 0) std::cout << "(" << operands[i] << ")";
        else std::cout << operands[i];
        if (i < count - 1) {
            if (i % 2 == 0) std::cout << " - ";
            else std::cout << " + ";
        }
    }
    std::cout << "\n";
}

void CustomExpressionEvaluator::logToFile(const std::string& filename) const {
    std::ofstream out(filename, std::ios::app);
    for (size_t i = 0; i < count; ++i) {
        if (operands[i] < 0) out << "(" << operands[i] << ")";
        else out << operands[i];
        if (i < count - 1) {
            if (i % 2 == 0) out << " - ";
            else out << " + ";
        }
    }
    out << "\n";
}

void CustomExpressionEvaluator::shuffle() {
    // отрицательные вперед, положительные назад
    std::stable_partition(operands, operands + count, [](double x) { return x < 0; });
}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j) {
    if (i >= count || j >= count) return;
    if (operands[i] < 0 && operands[j] >= 0) {
        std::swap(operands[i], operands[j]);
    }
}