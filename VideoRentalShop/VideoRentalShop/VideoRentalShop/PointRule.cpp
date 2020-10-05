#include "pch.h"
#include "PointRule.h"

void PointRule::Register(VideoType type, int point)
{
	m_rule[type] = point;
}

int PointRule::GetPoint(VideoType type)
{
	auto it = m_rule.find(type);
	if (it == m_rule.end()) return 0;

	return it->second;
}