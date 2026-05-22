#include "Shop.h"
#include <iostream>

Shop::Shop(const std::string& name, const std::string& address, int foundationYear, int number,
           double totalProfit, double income, const std::string& workingHours,
           int discountClients, bool isRoundTheClock)
    : name(name), address(address), foundationYear(foundationYear), number(number),
      totalProfit(totalProfit), income(income), workingHours(workingHours),
      discountClients(discountClients), isRoundTheClock(isRoundTheClock) {}

Shop::~Shop() {}

std::string Shop::getName() const {
    return name;
}

double Shop::getTotalProfit() const {
    return totalProfit;
}

void Shop::printInfo() const {
    std::cout << "Магазин: " << name << "\n"
              << "Адрес: " << address << "\n"
              << "Год основания: " << foundationYear << "\n"
              << "Номер: " << number << "\n"
              << "Прибыль: " << totalProfit << "\n"
              << "Доход: " << income << "\n"
              << "Часы работы: " << workingHours << "\n"
              << "Клиентов со скидкой: " << discountClients << "\n"
              << "Круглосуточно: " << (isRoundTheClock ? "да" : "нет") << "\n";
}