#pragma once
#include <set>

class Change;
class ChangeRule
{
private:
	std::set<int, std::greater<int>> m_quotient;

public:
	void AddQuotient(int value);
	std::shared_ptr<Change> CalculateByPolicy(int amount);

private:
	using Quotient = int;
	using Remain = int;

	std::pair<Quotient, Remain> Division(int amount, int quotient);
};