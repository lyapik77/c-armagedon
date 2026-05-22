#ifndef SHOP_H
#define SHOP_H

#include <string>
#include "ITaxPayment.h"

class Shop : public ITaxPayment {
protected:
    std::string name;
    std::string address;
    int foundationYear;
    int number;
    double totalProfit;
    double income;
    std::string workingHours;
    int discountClients;
    bool isRoundTheClock;

public:
    Shop(const std::string& name, const std::string& address, int foundationYear, int number,
         double totalProfit, double income, const std::string& workingHours,
         int discountClients, bool isRoundTheClock);

    virtual ~Shop();

    virtual void payTax() override = 0;   // остаётся чистым

    // Геттеры и методы
    std::string getName() const;
    double getTotalProfit() const;
    void printInfo() const;
};

#endif // SHOP_H