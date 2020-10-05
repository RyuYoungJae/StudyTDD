#pragma once
#include <unordered_map>
#include "VideoType.h"

class PointRule
{
private:
	std::unordered_map<VideoType, int> m_rule;

public:
	void Register(VideoType type, int point);
	int GetPoint(VideoType type);
};