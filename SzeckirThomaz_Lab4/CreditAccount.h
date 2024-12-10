#pragma once
#include "BaseAccount.h"
class CreditAccount : public BaseAccount
{
private: 
	int accAmountSpent;

public:
	CreditAccount();
	void Withdraw(float amount);
};