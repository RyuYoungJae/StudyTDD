#include "pch.h"
#include "RentalSystemTests.h"
#include "VideoType.h"
#include "PointRule.cpp"
#include "DiscountRule.cpp"
#include "RentCalculator.cpp"
#include "RentalRecord.cpp"
#include "Customer.cpp"

TEST(VideoTests, Tag_Create_Equal)
{
	auto video = std::make_shared<Video>();
	video->Tag("블랙머니", 1000, VideoType::MOVIE);

	EXPECT_EQ(video->ToString(), "블랙머니:1000:1");
}

TEST(PointRuleTests, Register_MOVIE3Point_Get3point)
{
	auto rule = std::make_shared<PointRule>();
	rule->Register(VideoType::MOVIE, 3);

	EXPECT_EQ(rule->GetPoint(VideoType::MOVIE), 3);
}

TEST(DiscountRuleTests, Register_RentalDays4_True)
{
	auto rule = std::make_shared<DiscountRule>();
	rule->Register(VideoType::MOVIE, 4, 0.5);

	auto rateInfo = rule->GetDiscountRate(VideoType::MOVIE);
	EXPECT_TRUE(rateInfo.first == 4 && rateInfo.second == 0.5);
}

TEST(RentCalculatorTests, GetRentalCharge_MovieRental5Days_3500Equal)
{
	auto m_video = std::make_shared<Video>();
	m_video->Tag("블랙머니", 1000, VideoType::MOVIE);
	EXPECT_EQ(m_video->ToString(), "블랙머니:1000:1");

	auto calc = std::make_shared<RentCalculator>();
	calc->RegisterDiscountRule(VideoType::MOVIE, 4, 0.5);
	
	EXPECT_EQ(calc->GetRentalCost(m_video, 5), 4000); ;
}

TEST(RentalRecordTests, Add_RentalVideo_1Equal)
{
	auto m_video = std::make_shared<Video>();
	m_video->Tag("블랙머니", 1000, VideoType::MOVIE);

	auto calc = std::make_shared<RentCalculator>();
	calc->RegisterDiscountRule(VideoType::MOVIE, 4, 0.5);

	auto rule = std::make_shared<PointRule>();
	rule->Register(VideoType::MOVIE, 3);

	auto cost = calc->GetRentalCost(m_video, 10);

	auto record = std::make_shared<RentalRecord>();
	record->Add(m_video, 6, cost, rule->GetPoint(m_video->GetType()));
	
	EXPECT_EQ(record->GetCount(), 1);
}

TEST(RentalRecordTests, GetRentalCost_TotalCost_36800Equal)
{
	auto video1 = std::make_shared<Video>();
	video1->Tag("블랙머니", 1000, VideoType::MOVIE);

	auto video2 = std::make_shared<Video>();
	video2->Tag("머니볼", 1500, VideoType::SPORTS);

	auto video3 = std::make_shared<Video>();
	video3->Tag("아마존의눈물", 2000, VideoType::DOCU);

	auto calc = std::make_shared<RentCalculator>();
	calc->RegisterDiscountRule(VideoType::MOVIE, 3, 0.5);
	calc->RegisterDiscountRule(VideoType::DOCU, 4, 0.3);

	auto record = std::make_shared<RentalRecord>();
	record->Add(video1, 10, calc->GetRentalCost(video1, 10), 1); //6000
	record->Add(video2, 10, calc->GetRentalCost(video2, 10), 1); //15000
	record->Add(video3, 10, calc->GetRentalCost(video3, 10), 1); //15800

	EXPECT_EQ(record->GetCost(), 36800);
}

TEST(RentalRecordTests, GetBonusPoint_TotalPoint_4Equal)
{
	auto video1 = std::make_shared<Video>();
	video1->Tag("블랙머니", 1000, VideoType::MOVIE);

	auto video2 = std::make_shared<Video>();
	video2->Tag("머니볼", 1500, VideoType::SPORTS);

	auto video3 = std::make_shared<Video>();
	video3->Tag("아마존의눈물", 2000, VideoType::DOCU);

	auto calc = std::make_shared<RentCalculator>();
	calc->RegisterDiscountRule(VideoType::MOVIE, 3, 0.5);
	calc->RegisterDiscountRule(VideoType::DOCU, 4, 0.3);

	auto point = std::make_shared<PointRule>();
	point->Register(VideoType::SPORTS, 2);
	point->Register(VideoType::MOVIE, 1);
	point->Register(VideoType::DOCU, 1);

	auto record = std::make_shared<RentalRecord>();
	record->Add(video1, 10, calc->GetRentalCost(video1, 10), point->GetPoint(video1->GetType())); 
	record->Add(video2, 10, calc->GetRentalCost(video2, 10), point->GetPoint(video2->GetType()));
	record->Add(video3, 10, calc->GetRentalCost(video3, 10), point->GetPoint(video3->GetType()));

	EXPECT_EQ(record->GetBonusPoint(), 4);
}

TEST(RentalRecordTests, Display_RentalInfo_Equal)
{
	auto video1 = std::make_shared<Video>();
	video1->Tag("블랙머니", 1000, VideoType::MOVIE);

	auto video2 = std::make_shared<Video>();
	video2->Tag("머니볼", 1500, VideoType::SPORTS);

	auto video3 = std::make_shared<Video>();
	video3->Tag("아마존의눈물", 2000, VideoType::DOCU);

	auto calc = std::make_shared<RentCalculator>();
	calc->RegisterDiscountRule(VideoType::MOVIE, 3, 0.5);
	calc->RegisterDiscountRule(VideoType::DOCU, 4, 0.3);

	auto point = std::make_shared<PointRule>();
	point->Register(VideoType::MOVIE, 1);
	point->Register(VideoType::SPORTS, 2);
	point->Register(VideoType::DOCU, 1);

	auto record = std::make_shared<RentalRecord>();
	record->Add(video1, 10, calc->GetRentalCost(video1, 10), point->GetPoint(video1->GetType()));
	record->Add(video2, 10, calc->GetRentalCost(video2, 10), point->GetPoint(video2->GetType()));
	record->Add(video3, 10, calc->GetRentalCost(video3, 10), point->GetPoint(video3->GetType()));

	EXPECT_EQ(record->Display(), 
		"3-블랙머니:1000:1:10:6000,머니볼:1500:2:10:15000,아마존의눈물:2000:3:10:15800,-36800-4");
	
}

TEST(Customer, Rent_AddTotalPoint_Equal)
{
	auto video1 = std::make_shared<Video>();
	video1->Tag("블랙머니", 1000, VideoType::MOVIE);

	auto video2 = std::make_shared<Video>();
	video2->Tag("머니볼", 1500, VideoType::SPORTS);

	auto video3 = std::make_shared<Video>();
	video3->Tag("아마존의눈물", 2000, VideoType::DOCU);

	auto calc = std::make_shared<RentCalculator>();
	calc->RegisterDiscountRule(VideoType::MOVIE, 3, 0.5);
	calc->RegisterDiscountRule(VideoType::DOCU, 4, 0.3);

	auto point = std::make_shared<PointRule>();
	point->Register(VideoType::MOVIE, 1);
	point->Register(VideoType::SPORTS, 2);
	point->Register(VideoType::DOCU, 1);

	auto customer = std::make_shared<Customer>("유영재", 100);
	customer->Rent(video1, 10, calc->GetRentalCost(video1, 10), point->GetPoint(video1->GetType()));
	customer->Rent(video2, 10, calc->GetRentalCost(video2, 10), point->GetPoint(video2->GetType()));
	customer->Rent(video3, 10, calc->GetRentalCost(video3, 10), point->GetPoint(video3->GetType()));
	
	EXPECT_EQ(customer->GetTotalPoint(), 104);
}

TEST_F(RentalSystemTests, RegisterVideo_afterFind_NotNull)
{
	RegisterVideos();

	auto result = m_system->FindVideo("블랙머니");
	EXPECT_TRUE(result != nullptr);
}

TEST_F(RentalSystemTests, RegisterAccount_afterFind_NotNull)
{
	m_system->RegisterCustomer("유영재", "01012345678");

	auto result = m_system->FindCustomer("01012345678");
	EXPECT_TRUE(result != nullptr);
}

