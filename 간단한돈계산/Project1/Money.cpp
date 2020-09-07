#include "Money.h"

Money::Money(const std::string& currency, double amount) : m_currency(currency), m_amount(amount)
{
}

double Money::GetAmount()
{
	return m_amount;
}

std::string Money::GetCurrency()
{
	return m_currency;
}

std::shared_ptr<Money> Money::Times(int value)
{
	return std::make_shared<Money>(GetCurrency(), m_amount * value);
}