#include "pch.h"
#include "Drink.h"

std::string Drink::GetName()
{
	return m_name;
}

std::shared_ptr<Drink> Drink::GetDrink()
{
	if (m_count <= 0) return nullptr;

	--m_count;

	return std::make_shared<Drink>(GetName(), 0, 1);
}

int Drink::GetCount()
{
	return m_count;
}

std::string Drink::ToString()
{
	return m_name + ":" + std::to_string(m_amount) + ":" + std::to_string(m_count);
}