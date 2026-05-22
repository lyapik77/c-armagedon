#ifndef PHARMACY_H
#define PHARMACY_H

#include "Shop.h"

class Pharmacy : public Shop {
public:
    Pharmacy(const std::string& name, const std::string& address, int foundationYear, int number,
             double totalProfit, double income, const std::string& workingHours,
             int discountClients, bool isRoundTheClock);

    void payTax() override;
};

#endif // PHARMACY_H