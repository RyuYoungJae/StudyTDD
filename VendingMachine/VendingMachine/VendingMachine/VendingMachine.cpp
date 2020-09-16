#include "pch.h"
#include "VendingMachine.h"
#include "Drink.h"

VendingMachine::VendingMachine() : m_drinks{}, m_money{0}
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
	if (!drink->EnableBuy(GetSavingMoney())) return nullptr;

	m_money -= drink->GetAmount();

	return drink->GetDrink();
}

int VendingMachine::GetRemainCount(const std::string& name)
{
	auto it = m_drinks.find(name);
	if (it == m_drinks.end()) return -1;

	auto& drink = it->second;
	return drink->GetCount();
}

void VendingMachine::PutMoney(int amount)
{
	m_money = amount;
}

int VendingMachine::GetSavingMoney()
{
	return m_money;
}

int VendingMachine::ReturnMoney()
{
	auto result = m_money;
	m_money = 0;

	return result;
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