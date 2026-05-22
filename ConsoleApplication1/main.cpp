#include <iostream>
#include <fstream>
#include "ExpressionEvaluator.h"
#include "Summator.h"
#include "CustomExpressionEvaluator.h"
#include "IShuffle.h"

int main() {
    setlocale(LC_ALL, "Russian");

    ExpressionEvaluator* evaluators[3];

    // CustomExpressionEvaluator: 5 операндов, группа 5, 4, -2, 9, 3
    CustomExpressionEvaluator* custom = new CustomExpressionEvaluator(5);
    double customOps[] = { 5, 4, -2, 9, 3 };
    custom->setOperands(customOps, 5);
    evaluators[0] = custom;

    // Summator: 7 операндов, группа 5, 12.5, 9, -1.5, -9.5, 0, 11
    Summator* summ = new Summator(7);
    double summOps[] = { 5, 12.5, 9, -1.5, -9.5, 0, 11 };
    summ->setOperands(summOps, 7);
    evaluators[1] = summ;


    std::cout << "=== ЛОГИРОВАНИЕ ===\n";
    for (int i = 0; i < 3; ++i) {
        evaluators[i]->logToScreen();
        std::cout << "Result: " << evaluators[i]->calculate() << "\n\n";
        evaluators[i]->logToFile("Lab3.log");
    }

    std::cout << "=== ПЕРЕМЕШИВАНИЕ (только для IShuffle) ===\n";
    for (int i = 0; i < 3; ++i) {
        IShuffle* shuffleable = dynamic_cast<IShuffle*>(evaluators[i]);
        if (shuffleable) {
            std::cout << "Объект " << i + 1 << " поддерживает IShuffle.\n";
            std::cout << "До: ";
            evaluators[i]->logToScreen();
            std::cout << "Результат до: " << evaluators[i]->calculate() << "\n";

            // shuffle() — отрицательные вперед
            shuffleable->shuffle();
            std::cout << "После shuffle(): ";
            evaluators[i]->logToScreen();
            std::cout << "Результат после: " << evaluators[i]->calculate() << "\n";

            // shuffle(2,4) — если 2-й отриц, а 4-й полож — поменять (индексы с 0)
            if (evaluators[i]->getCount() > 4) {
                shuffleable->shuffle(2, 4);
                std::cout << "После shuffle(2,4): ";
                evaluators[i]->logToScreen();
                std::cout << "Результат: " << evaluators[i]->calculate() << "\n";
            }
            std::cout << "---\n";
        }
        else {
            std::cout << "Объект " << i + 1 << " не поддерживает IShuffle.\n";
        }
    }

    for (int i = 0; i < 3; ++i) delete evaluators[i];
    return 0;
}