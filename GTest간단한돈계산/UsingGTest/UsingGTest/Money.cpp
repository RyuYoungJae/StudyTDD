#include "pch.h"
#include "Money.h"

Money::Money() : m_currency{}, m_amount{}
{
}

Money::Money(const std::string& currency, int amount)
	: m_currency{currency}, m_amount{amount}
{
}

std::shared_ptr<Money> Money::Times(int value)
{
	return std::make_shared<Money>(GetCurrency(), m_amount * value);
}

std::string Money::GetCurrency() const
{
	return m_currency;
}

int Money::GetAmount() const
{
	return m_amount;
}

bool Money::Equal(const std::shared_ptr<Money>& rhs)
{
	return GetCurrency() == rhs->GetCurrency()
		&& GetAmount() == rhs->GetAmount();
}