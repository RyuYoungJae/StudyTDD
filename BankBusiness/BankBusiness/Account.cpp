#include "pch.h"
#include "Account.h"

Account::Account(int money) : m_balance{ money }
{
}

int Account::GetBalance()
{
	return m_balance;
}

void Account::Deposit(int money)
{
	if (money <= 0) return;

	m_balance += money;
}

void Account::Withdraw(int money)
{
	if (money > GetBalance()) return;

	m_balance -= money;
}