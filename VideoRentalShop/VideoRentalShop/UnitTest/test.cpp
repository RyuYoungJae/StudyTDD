#include "pch.h"
#include "Video.cpp"
#include "RentalSystem.cpp"

TEST(VideoTests, Tag_Create_Equal)
{
	auto video = std::make_shared<Video>();
	video->Tag("블랙머니", 1000, 100);

	EXPECT_EQ(video->ToString(), "블랙머니:1000:100");
}

TEST(RentalSystemTests, Register_afterFind_NotNull)
{
	auto video = std::make_shared<Video>();
	video->Tag("블랙머니", 1000, 100);

	auto system = std::make_shared<RentalSystem>();
	system->Register(video);

	auto result = system->Find("블랙머니");
	EXPECT_TRUE(result != nullptr);
}