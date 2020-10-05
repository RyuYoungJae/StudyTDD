#pragma once
#include <string>

class Video
{
private:
	std::string m_title;
	int m_cost;
	int m_point;

public:
	Video();

	void Tag(std::string&& title, int cost, int point);
	
	std::string GetTitle();
	std::string ToString();
};