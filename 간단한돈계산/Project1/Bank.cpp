#include "Money.h"
#include "Bank.h"

void Bank::AddRate(const std::string& from, const std::string& to, float rate)
{
	m_rates[{from, to}] = rate;
}

std::shared_ptr<Money> Bank::Exchange(const std::shared_ptr<Money>& from, const std::string& to)
{
	if (from->GetCurrency() == to) return from;

	auto it = m_rates.find({ from->GetCurrency(), to });
	if (it == m_rates.end()) return nullptr;

	auto rate = it->second;

	return std::make_shared<Money>(to, from->GetAmount() * rate);
}

std::shared_ptr<Money> Bank::Sum(const std::shared_ptr<Money>& a, const std::shared_ptr<Money>& b, const std::string& target)
{
	auto changeA = Exchange(a, target);
	auto changeB = Exchange(b, target);

	if (changeA == nullptr
		|| changeB == nullptr) return nullptr;

	return std::make_shared<Money>(target, changeA->GetAmount() + changeB->GetAmount());
}