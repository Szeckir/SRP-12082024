#pragma once
class BaseAccount
{
public:
	BaseAccount() {
		accBalance_ = 0;
		accWithdrawls_ = 0;
	}

protected:
	float accBalance_;
	int accWithdrawls_;

public:
	virtual void Withdraw(float amount);
	virtual void Deposit(float amount);
	float GetBalance() { return accBalance_; }

};