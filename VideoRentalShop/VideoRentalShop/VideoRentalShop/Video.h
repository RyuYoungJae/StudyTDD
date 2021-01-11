#pragma once
#include <string>
#include "VideoType.h"

class Video
{
private:
	std::string m_title;
	int m_cost;
	VideoType m_type;

public:
	Video();

	void Tag(std::string&& title, int cost, VideoType type);

	std::string GetTitle();
	VideoType GetType();
	int GetCost();

	std::string ToString();
};