#include "pch.h"
#include "Video.cpp"
#include "RentalSystem.cpp"

TEST(VideoTests, Tag_Create_Equal)
{
	auto video = std::make_shared<Video>();
	video->Tag("���Ӵ�", 1000, 100);

	EXPECT_EQ(video->ToString(), "���Ӵ�:1000:100");
}

TEST(RentalSystemTests, Register_afterFind_NotNull)
{
	auto video = std::make_shared<Video>();
	video->Tag("���Ӵ�", 1000, 100);

	auto system = std::make_shared<RentalSystem>();
	system->Register(video);

	auto result = system->Find("���Ӵ�");
	EXPECT_TRUE(result != nullptr);
}