#include "pch.h"
#include "Video.h"
#include "RentalRecord.h"
#include "Customer.h"

Customer::Customer(int bonusPoint) : m_retal { std::make_unique<RentalRecord>() }, m_totalBonus { bonusPoint }
{
}

void Customer::Rent(const std::shared_ptr<Video>& video, int days, int cost, int bonusPoint)
{
	m_retal->Add(video, days, cost, bonusPoint);
	AddBonusPoint(bonusPoint);
}
 
void Customer::AddBonusPoint(int point)
{
	m_totalBonus += point;
}

int Customer::GetTotalPoint()
{
	return m_totalBonus;
}