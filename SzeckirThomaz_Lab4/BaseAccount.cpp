
#include "BaseAccount.h"

void BaseAccount::Withdraw(float amount)
{
	accWithdrawls_++;
	accBalance_ = accBalance_ - amount;
}

void BaseAccount::Deposit(float amount)
{
	accBalance_ = accBalance_ + amount;

}
