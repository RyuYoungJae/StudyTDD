#include "pch.h"
#include "Change.h"

void Change::Add(int amount, int count)
{
	m_money.emplace_back(Money(amount, count));
}

int Change::GetTotalMoney()
{
	auto result = 0;

	for (auto& money : m_money)
	{
		result += (money.Amount * money.Count);
	}

	return result;
}

std::string Change::ToString()
{
	std::string result{};

	for (auto& money : m_money)
	{
		if (!result.empty()) result += ",";

		result += std::to_string(money.Amount) + ":" + std::to_string(money.Count);
	}

	return result;
}
