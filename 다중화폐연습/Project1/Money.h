#pragma once
#include <string>
#include <memory>

class Money
{
public:
	Money(const std::string& currency, double amount);

	std::shared_ptr<Money> Times(int value);
	double GetAmount();
	std::string GetCurrency();

public:
	std::string m_currency;
	double m_amount;
};