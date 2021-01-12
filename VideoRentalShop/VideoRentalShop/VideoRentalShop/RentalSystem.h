#pragma once
#include <memory>
#include <string>
#include <unordered_map>

class Video;
class Customer;
class RentCalculator;
class PointRule;
class RentalSystem
{
private:
	std::unordered_map<std::string, std::shared_ptr<Video>> m_titles;
	std::unordered_map<std::string, std::shared_ptr<Customer>> m_customers;

	std::unique_ptr<RentCalculator> m_costCalculator;
	std::unique_ptr<PointRule> m_pointRule;

public:
	RentalSystem();
	virtual ~RentalSystem() = default;

	void RegisterVideo(const std::string& videoName, int cost, VideoType type);
	std::shared_ptr<Video> FindVideo(const std::string& title);
	void RegisterCustomer(const std::string& name, const std::string& phoneNum);
	std::shared_ptr<Customer> FindCustomer(const std::string& phoneNum);

	void RegisterDiscountRule(VideoType type, int moreTanDays, double rate);
	void RegisterBonusPointRule(VideoType type, int point);

	bool Rental(const std::string& phoneNum, const std::string& videoName, int days);
};