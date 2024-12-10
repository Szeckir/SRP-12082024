#include "SavingsAccount.h"
#include <string>
#include <iostream>

SavingsAccount::SavingsAccount() : BaseAccount() {}

void SavingsAccount::Withdraw(float amount)
{
	if (accBalance_ >= amount) {
		if (accWithdrawls_ > 3) {
			std::cout << "Withdraw limit" << std::endl;
		}
		else {
			accBalance_ = accBalance_ - amount;
		}
	}
}
