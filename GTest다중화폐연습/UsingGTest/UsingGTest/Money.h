#pragma once

class Money
{
protected:
	std::string m_currency;
	int m_amount;

public:
	Money();
	Money(const std::string& currency, int amount);
	std::shared_ptr<Money> Times(int value);

	std::string GetCurrency() const;
	int GetAmount() const;

	bool Equal(const std::shared_ptr<Money>& rhs);
};