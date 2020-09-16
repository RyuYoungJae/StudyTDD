#include "pch.h"
#include "Change.h"
#include "ChangeRule.h"

void ChangeRule::AddQuotient(int value)
{
	m_quotient.insert(value);
}

std::shared_ptr<Change> ChangeRule::CalculateByPolicy(int amount)
{
	//NOTE::가장 적은 동전의 수로 반환
	auto change = std::make_shared<Change>();
	
	auto remain = amount;
	for (auto& quotient : m_quotient)
	{
		auto result = Division(remain, quotient);
		if (result.first > 0) change->Add(quotient, result.first);
		
		remain = result.second;
	}

	return change;
}

std::pair<ChangeRule::Quotient, ChangeRule::Remain> ChangeRule::Division(int amount, int quotient)
{
	return { amount / quotient, amount % quotient };
}