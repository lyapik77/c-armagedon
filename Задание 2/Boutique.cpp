#include "Boutique.h"
#include <iostream>

Boutique::Boutique(const std::string& name, const std::string& address, int foundationYear, int number,
                   double totalProfit, double income, const std::string& workingHours,
                   int discountClients, bool isRoundTheClock)
    : Shop(name, address, foundationYear, number, totalProfit, income,
           workingHours, discountClients, isRoundTheClock) {}

void Boutique::payTax() {
    double profitTaxRate = 0.20;    // налог на прибыль 20%
    double landTaxRate = 0.05;      // земельный налог 5%
    double totalTaxRate = profitTaxRate + landTaxRate;
    double tax = totalProfit * totalTaxRate;
    if (tax > totalProfit) tax = totalProfit;
    totalProfit -= tax;
    std::cout << "Бутик \"" << name << "\": уплачены налоги (прибыль " << profitTaxRate * 100
              << "% + земельный " << landTaxRate * 100 << "%) = " << tax
              << ". Новая прибыль: " << totalProfit << std::endl;
}