#include "pch.h"
#include "Video.h"
#include "Customer.h"
#include "RentCalculator.h"
#include "PointRule.h"
#include "RentalSystem.h"

RentalSystem::RentalSystem() 
	: m_costCalculator { std::make_unique<RentCalculator>() }
	, m_pointRule { std::make_unique<PointRule>() }
{
}

void RentalSystem::RegisterVideo(const std::string& title, int cost, VideoType type)
{
	auto video = std::make_shared<Video>();
	video->Tag(title, cost, type);

	m_titles[video->GetTitle()] = video;
}

std::shared_ptr<Video> RentalSystem::FindVideo(const std::string& title)
{
	auto it = m_titles.find(title);
	if (it == m_titles.end()) return nullptr;

	return it->second;
}

void RentalSystem::RegisterCustomer(const std::string& name, const std::string& phoneNum)
{
	auto customer = std::make_shared<Customer>(name);
	m_customers[phoneNum] = customer;
}

std::shared_ptr<Customer> RentalSystem::FindCustomer(const std::string& phoneNum)
{
	auto it = m_customers.find(phoneNum);
	if (it == m_customers.end()) return nullptr;

	return it->second;
}

void RentalSystem::RegisterDiscountRule(VideoType type, int moreTanDays, double rate)
{
	m_costCalculator->RegisterDiscountRule(type, moreTanDays, rate);
}

void RentalSystem::RegisterBonusPointRule(VideoType type, int point)
{
	m_pointRule->Register(type, point);
}

bool RentalSystem::Rental(const std::string& phoneNum, const std::string& videoName, int days)
{
	auto customer = FindCustomer(phoneNum);
	if (customer == nullptr) return false;

	auto video = FindVideo(videoName);
	if (video == nullptr) return false;

	customer->Rent(video, days, m_costCalculator->GetRentalCost(video, days), m_pointRule->GetPoint(video->GetType()));
	return true;
}