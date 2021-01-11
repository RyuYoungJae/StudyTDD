#pragma once
#include <memory>
#include <vector>

class Video;
class RentalRecord
{
private:
	std::vector<std::shared_ptr<Video>> m_records;

public:
	void Add(const std::shared_ptr<Video>& video, int days, int cost, int bonusPoint);
	int GetCount();
};