#include "CheckingAccount.h"
#include <string>
#include <iostream>

CheckingAccount::CheckingAccount() : BaseAccount() {}

void CheckingAccount::Withdraw(float amount)
{
	if (accBalance_ >= amount) {
		if (accWithdrawls_ > 10) {
			BaseAccount::Withdraw(amount + 5);
		}
		else {
			BaseAccount::Withdraw(amount);
		}
	}
}
