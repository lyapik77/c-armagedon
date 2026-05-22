#include "Divisor.h"
#include <iostream>
#include <fstream>

Divisor::Divisor(size_t n) : ExpressionEvaluator(n) {}

double Divisor::calculate() const {
    if (count == 0) return 0;
    double result = operands[0];
    for (size_t i = 1; i < count; ++i) {
        if (operands[i] == 0) return 0;
        result /= operands[i];
    }
    return result;
}

void Divisor::logToScreen() const {
    std::cout << "[ " << count << " ]\n";
    for (size_t i = 0; i < count; ++i) {
        if (operands[i] < 0) std::cout << "(" << operands[i] << ")";
        else std::cout << operands[i];
        if (i < count - 1) std::cout << " / ";
    }
    std::cout << "\n";
}

void Divisor::logToFile(const std::string& filename) const {
    std::ofstream out(filename, std::ios::app);
    for (size_t i = 0; i < count; ++i) {
        if (operands[i] < 0) out << "(" << operands[i] << ")";
        else out << operands[i];
        if (i < count - 1) out << " / ";
    }
    out << "\n";
}