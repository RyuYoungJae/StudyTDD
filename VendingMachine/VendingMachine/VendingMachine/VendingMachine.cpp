#include "pch.h"
#include "VendingMachine.h"
#include "Drink.h"

VendingMachine::VendingMachine()
{
}


VendingMachine::~VendingMachine()
{
}

void VendingMachine::RegisterDrink(std::shared_ptr<Drink> drink)
{
	m_drinks[drink->GetName()] = drink;
}

std::shared_ptr<Drink> VendingMachine::Push(const std::string& name)
{
	auto it = m_drinks.find(name);
	if (it == m_drinks.end()) return nullptr;

	auto& drink = it->second;
	return drink->GetDrink();
}

int VendingMachine::GetRemainCount(const std::string& name)
{
	auto it = m_drinks.find(name);
	if (it == m_drinks.end()) return -1;

	auto& drink = it->second;
	return drink->GetCount();
}

std::string VendingMachine::ToString()
{
	std::string result{};

	for (auto it : m_drinks)
	{
		if (!result.empty()) result += ",";

		auto& drink = it.second;
		result += drink->ToString();
	}

	return result;
}