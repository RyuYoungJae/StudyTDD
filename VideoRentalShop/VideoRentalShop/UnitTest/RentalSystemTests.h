#pragma once
#include "Video.cpp"
#include "RentalSystem.cpp"

class RentalSystemTests : public testing::Test
{
public:
	std::unique_ptr<RentalSystem> m_system;

	RentalSystemTests() : m_system{std::make_unique<RentalSystem>()}
	{}

	void RegisterVideos()
	{
		auto video = std::make_shared<Video>();
		video->Tag("블랙머니", 1000, VideoType::MOVIE);

		m_system->RegisterVideo(video);
	}
};