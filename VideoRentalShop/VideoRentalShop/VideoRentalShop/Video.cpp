#include "pch.h"
#include "Video.h"

Video::Video() : m_title{""}, m_cost{0}, m_point{0}
{}

void Video::Tag(std::string&& title, int cost, int point)
{
	m_title = std::move(title);
	m_cost = cost;
	m_point = point;
}

std::string Video::GetTitle()
{
	return m_title;
}

std::string Video::ToString()
{
	return m_title + ":" + std::to_string(m_cost) + ":" + std::to_string(m_point);
}