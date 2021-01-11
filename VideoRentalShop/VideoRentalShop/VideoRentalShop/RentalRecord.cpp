#include "pch.h"
#include "Video.h"
#include "RentalRecord.h"

void RentalRecord::Add(const std::shared_ptr<Video>& video, int days, int cost, int bonusPoint)
{
	m_records.push_back(video);
}

int RentalRecord::GetCount()
{
	return static_cast<int>(m_records.size());
}