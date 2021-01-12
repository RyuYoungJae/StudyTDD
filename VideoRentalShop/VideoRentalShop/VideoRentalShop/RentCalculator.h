#pragma once
#include <memory>
#include "VideoType.h"

class DiscountRule;
class Video;
class RentCalculator
{
private:
	std::unique_ptr<DiscountRule> m_discountRule;

public:
	RentCalculator();
	virtual ~RentCalculator() = default;

	void RegisterDiscountRule(VideoType type, int moreTanDays, double rate);
	int GetRentalCost(const std::shared_ptr<Video>& video, int days);
};

