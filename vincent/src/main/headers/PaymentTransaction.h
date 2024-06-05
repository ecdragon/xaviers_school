#ifndef PAYMENTTRANSACTION_H
#define PAYMENTTRANSACTION_H

#include <string>
#include <iostream>

struct PaymentTransaction {
    int id;
    double amount;
    std::string description;

    PaymentTransaction(int id, double amount, const std::string& description);

    // Overload the output operator to print PaymentTransaction data
    friend std::ostream& operator<<(std::ostream& os, const PaymentTransaction& pt);
};

#endif // PAYMENTTRANSACTION_H
