#ifndef BOUTIQUE_H
#define BOUTIQUE_H

#include "Shop.h"

class Boutique : public Shop {
public:
    Boutique(const std::string& name, const std::string& address, int foundationYear, int number,
             double totalProfit, double income, const std::string& workingHours,
             int discountClients, bool isRoundTheClock);

    void payTax() override;
};

#endif // BOUTIQUE_H