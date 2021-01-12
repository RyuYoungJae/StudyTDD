#pragma once
#include <memory>

class Video;
class RentalRecord;
class Customer
{
private:
	std::string m_name;
	std::unique_ptr<RentalRecord> m_retal;
	int m_totalBonus;

public:
	Customer() = delete;
	Customer(const std::string& name);
	Customer(const std::string& name, int bonusPoint);
	virtual ~Customer() = default;

	void Rent(const std::shared_ptr<Video>& video, int days, int cost, int bonusPoint);
	void AddBonusPoint(int point);
	int GetTotalPoint();
};

