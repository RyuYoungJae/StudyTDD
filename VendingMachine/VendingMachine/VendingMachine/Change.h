#pragma once

class Change
{
private:
	struct Money
	{
		int Amount{ 0 };
		int Count{ 0 };

		Money(int _amount, int _count)
			: Amount(_amount)
			, Count(_count) {}
	};

private:
	std::vector<Money> m_money;
	
public:
	Change() = default;
	void Add(int amount, int count);

	int GetTotalMoney();
	std::string ToString();
};