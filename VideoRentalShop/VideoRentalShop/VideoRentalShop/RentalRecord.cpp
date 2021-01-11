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
