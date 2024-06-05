#include "PaymentTransaction.h"

PaymentTransaction::PaymentTransaction(int id, double amount, const std::string& description)
    : id(id), amount(amount), description(description) {}

std::ostream& operator<<(std::ostream& os, const PaymentTransaction& pt) {
    os << "ID: " << pt.id << ", Amount: " << pt.amount << ", Description: " << pt.description;
    return os;
}
