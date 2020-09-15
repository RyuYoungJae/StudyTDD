#pragma once
#include <string>

class Drink
{
protected:
	std::string m_name;
	int m_amount;
	int m_count;

public:
	Drink(const std::string& name, int amount, int count)
		: m_name{ name }
		, m_amount{ amount }
		, m_count{ count }
	{
	}

	std::string GetName();
	std::shared_ptr<Drink> GetDrink();
	int GetCount();

	std::string ToString();
};