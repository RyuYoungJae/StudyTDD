#pragma once
#include <unordered_map>
#include "VideoType.h"

class DiscountRule
{
private:
	using PeriodRate = std::pair<int, double>;
	std::unordered_map<VideoType, PeriodRate> m_rule;

public:
	void Register(VideoType type, int moreTanDays, double rate);
	PeriodRate GetDiscountRate(VideoType type);
};

