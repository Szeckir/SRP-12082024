#include "CreditAccount.h"
#include <iostream>
#include <string>

CreditAccount::CreditAccount() : BaseAccount(), accAmountSpent(0) {}

void CreditAccount::Withdraw(float amount)
{
    if (accBalance_ >= amount) {
        accBalance_ -= amount;
        accAmountSpent += amount;

        if (accAmountSpent > 40) {
            accBalance_ -= 5000; 
            std::cout << "Penalty applied for exceeding spending limit.\n";
        }
    }
}
