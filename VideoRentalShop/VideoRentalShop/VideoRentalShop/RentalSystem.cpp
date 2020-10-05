#include "pch.h"
#include "Video.h"
#include "RentalSystem.h"

void RentalSystem::Register(const std::shared_ptr<Video>& video)
{
	m_titles[video->GetTitle()] = video;
}

std::shared_ptr<Video> RentalSystem::Find(const std::string& title)
{
	auto it = m_titles.find(title);
	if (it == m_titles.end()) return nullptr;

	return it->second;
}