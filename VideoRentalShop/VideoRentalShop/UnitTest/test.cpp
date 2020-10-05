#include "pch.h"
#include "RentalSystemTests.h"
#include "VideoType.h"
#include "PointRule.cpp"

TEST(VideoTests, Tag_Create_Equal)
{
	auto video = std::make_shared<Video>();
	video->Tag("블랙머니", 1000, VideoType::MOVIE);

	EXPECT_EQ(video->ToString(), "블랙머니:1000:1");
}

TEST(PointRuleTests, Register_MOVIE3Point_Get3point)
{
	auto rule = std::make_shared<PointRule>();
	rule->Register(VideoType::MOVIE, 1);

	EXPECT_EQ(rule->GetPoint(VideoType::MOVIE), 1);
}

TEST_F(RentalSystemTests, Register_afterFind_NotNull)
{
	RegisterVideos();

	auto result = m_system->Find("블랙머니");
	EXPECT_TRUE(result != nullptr);
}