#pragma once
#include <map>

class Money;
class Bank
{
private:
	std::map<std::pair<std::string, std::string>, double> m_rates;

public:
	void AddRate(const std::string& from, const std::string& to, double rate);
	std::shared_ptr<Money> Exchange(const std::shared_ptr<Money>& from, const std::string& to);
};

