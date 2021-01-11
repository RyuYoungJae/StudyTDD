#include "pch.h"
#include "DiscountRule.h"
#include "Video.h"
#include "RentCalculator.h"

RentCalculator::RentCalculator() : m_discountRule{std::make_unique<DiscountRule>()}
{}

void RentCalculator::RegisterDiscountRule(VideoType type, int moreTanDays, double rate)
{
	m_discountRule->Register(type, moreTanDays, rate);
}

int RentCalculator::GetRentalCost(const std::shared_ptr<Video>&  video, int days)
{
	auto type = video->GetType();
	auto cost = video->GetCost();

	auto discountRule = m_discountRule->GetDiscountRate(type);
	if (discountRule.second == 0) return discountRule.second;

	if (days < discountRule.first) return cost * days;

	int discountDays = days - discountRule.first + 1;
	return static_cast<int>((days - discountDays) * cost + (discountDays * (cost * discountRule.second)));
}