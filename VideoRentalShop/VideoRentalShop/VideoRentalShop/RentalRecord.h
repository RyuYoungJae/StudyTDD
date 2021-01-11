#pragma once
#include <memory>
#include <vector>

class Video;
class RentalRecord
{
private:
	struct Record
	{
		std::shared_ptr<Video> Video = nullptr;
		int Cost = 0;
		int Point = 0;
		int Days = 0;
	};

private:
	std::vector<Record> m_records;

public:
	void Add(const std::shared_ptr<Video>& video, int days, int cost, int bonusPoint);
	int GetCount();
	int GetCost();
	int GetBonusPoint();
	std::string Display();
};