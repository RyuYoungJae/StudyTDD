#pragma once
#include <unordered_map>

class Drink;
class Change;
class ChangeRule;

class VendingMachine
{
private:
	std::unordered_map<std::string, std::shared_ptr<Drink>> m_drinks;
	int m_money;
	std::unique_ptr<ChangeRule> m_changeRule;

public:
	VendingMachine();
	~VendingMachine();

	void RegisterDrink(std::shared_ptr<Drink> drink);
	void RegisterChangeRule(std::unique_ptr<ChangeRule> rule);

	std::shared_ptr<Drink> Push(const std::string& name);
	int GetRemainCount(const std::string& name);
	void PutMoney(int amount);
	int GetSavingMoney();
	std::shared_ptr<Change> ReturnMoney();

	std::string ToString();
};

