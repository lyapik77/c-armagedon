#include "Summator.h"
#include <iostream>
#include <fstream>

Summator::Summator(size_t n) : ExpressionEvaluator(n) {}

double Summator::calculate() const {
    double sum = 0;
    for (size_t i = 0; i < count; ++i) sum += operands[i];
    return sum;
}

void Summator::logToScreen() const {
    std::cout << "[ " << count << " ]\n";
    for (size_t i = 0; i < count; ++i) {
        if (operands[i] < 0) std::cout << "(" << operands[i] << ")";
        else std::cout << operands[i];
        if (i < count - 1) std::cout << " + ";
    }
    std::cout << "\n";
}

void Summator::logToFile(const std::string& filename) const {
    std::ofstream out(filename, std::ios::app);
    for (size_t i = 0; i < count; ++i) {
        if (operands[i] < 0) out << "(" << operands[i] << ")";
        else out << operands[i];
        if (i < count - 1) out << " + ";
    }
    out << "\n";
}