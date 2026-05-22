#include "Pharmacy.h"
#include <iostream>

Pharmacy::Pharmacy(const std::string& name, const std::string& address, int foundationYear, int number,
                   double totalProfit, double income, const std::string& workingHours,
                   int discountClients, bool isRoundTheClock)
    : Shop(name, address, foundationYear, number, totalProfit, income,
           workingHours, discountClients, isRoundTheClock) {}

void Pharmacy::payTax() {
    double taxRate = 0.20;          // налог на прибыль 20%
    double tax = totalProfit * taxRate;
    if (tax > totalProfit) tax = totalProfit;
    totalProfit -= tax;
    std::cout << "Аптека \"" << name << "\": уплачен налог на прибыль " << tax
              << " (ставка " << taxRate * 100 << "%). Новая прибыль: " << totalProfit << std::endl;
}