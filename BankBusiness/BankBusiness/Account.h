#pragma once
class Account
{
public:
	Account(int money);

	int GetBalance();
	void Deposit(int money);
	void Withdraw(int money);

private:
	int m_balance;
};

