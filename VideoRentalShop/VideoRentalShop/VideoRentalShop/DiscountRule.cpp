#include "pch.h"
#include "DiscountRule.h"

void DiscountRule::Register(VideoType type, int moreTanDays, double rate)
{
	m_rule[type] = { moreTanDays, rate };
}

DiscountRule::PeriodRate DiscountRule::GetDiscountRate(VideoType type)
{
	auto it = m_rule.find(type);
	if (it == m_rule.end()) return {};

	return it->second;
}