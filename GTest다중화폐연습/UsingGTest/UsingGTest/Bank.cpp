#include "pch.h"
#include "Money.h"
#include "EmptyMoney.h"
#include "Bank.h"

void Bank::AddRate(const std::string& from, const std::string& to, double rate)
{
	m_rates[{from, to}] = rate;
}

std::shared_ptr<Money> Bank::Exchange(const std::shared_ptr<Money>& from, const std::string& to)
{
	if (from->GetCurrency() == to) return from;

	auto it = m_rates.find({ from->GetCurrency(), to });
	if (it == m_rates.end()) return std::make_shared<EmptyMoney>();

	auto rate = it->second;
	return std::make_shared<Money>(to, from->GetAmount() * rate);
}