#pragma once
#include <memory>
#include "ChangeRule.h"

class VendingMachineTests : public testing::Test
{
public:
	std::unique_ptr<ChangeRule> MakeChangeRule()
	{
		auto rule = std::make_unique<ChangeRule>();
		rule->AddQuotient(500);
		rule->AddQuotient(100);
		rule->AddQuotient(50);
		rule->AddQuotient(10);

		return rule;
	}
};