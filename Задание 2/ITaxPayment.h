#ifndef ITAXPAYMENT_H
#define ITAXPAYMENT_H

class ITaxPayment {
public:
    virtual void payTax() = 0;
    virtual ~ITaxPayment() {}
};

#endif // ITAXPAYMENT_H