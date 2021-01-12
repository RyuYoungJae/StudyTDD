#pragma once
#include <memory>

class Video;
class RentalRecord;
class Customer
{
private:
	std::unique_ptr<RentalRecord> m_retal;
	int m_totalBonus;

public:
	Customer() = default;
	Customer(int bonusPoint);
	
	void Rent(const std::shared_ptr<Video>& video, int days, int cost, int bonusPoint);
	void AddBonusPoint(int point);
	int GetTotalPoint();
};

