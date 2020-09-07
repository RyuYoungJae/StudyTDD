#pragma once
#include <map>
#include <memory>

class Money;
class Bank
{
private:
	std::map<std::pair<std::string, std::string>, float> m_rates;

public:
	void AddRate(const std::string& from, const std::string& to, float rate);
	std::shared_ptr<Money> Exchange(const std::shared_ptr<Money>& from, const std::string& to);
	std::shared_ptr<Money> Sum(const std::shared_ptr<Money>& a, const std::shared_ptr<Money>& b, const std::string& target);
};

