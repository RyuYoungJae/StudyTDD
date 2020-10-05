#include "pch.h"
#include "Video.h"

Video::Video() : m_title{""}, m_cost{0}, m_type{VideoType::NONE}
{}

void Video::Tag(std::string&& title, int cost, VideoType type)
{
	m_title = std::move(title);
	m_cost = cost;
	m_type = type;
}

std::string Video::GetTitle()
{
	return m_title;
}

std::string Video::ToString()
{
	return m_title + ":" + std::to_string(m_cost) + ":" + std::to_string(static_cast<int>(m_type));
}