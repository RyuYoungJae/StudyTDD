#include "pch.h"
#include "Video.h"
#include "RentalRecord.h"

void RentalRecord::Add(const std::shared_ptr<Video>& video, int days, int cost, int bonusPoint)
{
	Record record;
	record.Video = video;
	record.Cost = cost;
	record.Point = bonusPoint;
	record.Days = days;

	m_records.push_back(record);
}

int RentalRecord::GetCount()
{
	return static_cast<int>(m_records.size());
}

int RentalRecord::GetCost()
{
	if (m_records.empty()) return 0;

	int total = 0;
	for (const auto& record : m_records)
	{
		total += record.Cost;
	}

	return total;
}

int RentalRecord::GetBonusPoint()
{
	if (m_records.empty()) return 0;

	int total = 0;
	for (const auto& record : m_records)
	{
		total += record.Point;
	}

	return total;
}

std::string RentalRecord::Display()
{
	std::string result = "";
	result += std::to_string(m_records.size());
	result += "-";
	
	for (const auto& record : m_records)
	{
		result += record.Video->ToString();
		result += ":";
		result += std::to_string(record.Days);
		result += ":";
		result += std::to_string(record.Cost);
		result += ",";
	}

	result += "-";
	result += std::to_string(GetCost());
	
	result += "-";
	result += std::to_string(GetBonusPoint());

	return result;
}
