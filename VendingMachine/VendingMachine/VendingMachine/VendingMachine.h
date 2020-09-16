#pragma once
#include <unordered_map>

class Drink;
class VendingMachine
{
private:
	std::unordered_map<std::string, std::shared_ptr<Drink>> m_drinks;
	int m_money;

public:
	VendingMachine();
	~VendingMachine();

	void RegisterDrink(std::shared_ptr<Drink> drink);
	std::shared_ptr<Drink> Push(const std::string& name);
	int GetRemainCount(const std::string& name);
	void PutMoney(int amount);
	int GetSavingMoney();
	int ReturnMoney();

	std::string ToString();
};

