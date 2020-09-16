#include "pch.h"
#include "VendingMachineTests.h"
#include <memory.h>
#include "VendingMachine.h"
#include "Drink.h"
#include "ChangeRule.h"
#include "Change.h"

TEST_F(VendingMachineTests, RegisterDrink_Coke600wonN10)
{
	auto machine = std::make_shared<VendingMachine>();
	machine->RegisterDrink(std::make_shared<Drink>("Coke", 600, 10));

	EXPECT_EQ(machine->ToString(), "Coke:600:10");
}

TEST_F(VendingMachineTests, PutMoney_1000_equal)
{
	auto machine = std::make_shared<VendingMachine>();
	machine->PutMoney(1000);

	EXPECT_EQ(machine->GetSavingMoney(), 1000);
}

TEST_F(VendingMachineTests, ReturnMoney_1000In_1000)
{
	auto machine = std::make_shared<VendingMachine>();
	auto rule = MakeChangeRule();
	machine->RegisterChangeRule(std::move(rule));
	machine->PutMoney(1000);
	auto money = machine->ReturnMoney();

	EXPECT_EQ(money->GetTotalMoney(), 1000);
}

TEST_F(VendingMachineTests, ReturnMoney_1000inN650Coke_Return350)
{
	auto machine = std::make_shared<VendingMachine>();
	auto rule = MakeChangeRule();
	machine->RegisterChangeRule(std::move(rule));
	machine->RegisterDrink(std::make_shared<Drink>("Coke", 650, 10));
	machine->PutMoney(1000);
	
	auto coke = machine->Push("Coke");
	auto change = machine->ReturnMoney();

	EXPECT_TRUE(coke != nullptr);
	EXPECT_EQ(change->GetTotalMoney(), 350);
}

TEST_F(VendingMachineTests, ReturnMoney_600inN650Coke_Return600)
{
	auto machine = std::make_shared<VendingMachine>();
	auto rule = MakeChangeRule();
	machine->RegisterChangeRule(std::move(rule));
	machine->RegisterDrink(std::make_shared<Drink>("Coke", 650, 10));
	machine->PutMoney(600);

	auto coke = machine->Push("Coke");
	auto change = machine->ReturnMoney();

	EXPECT_TRUE(coke == nullptr);
	EXPECT_EQ(change->GetTotalMoney(), 600);
}

TEST(ChangeRule, CalculateByPolicy_350_Return300N50)
{
	auto rule = std::make_shared<ChangeRule>();
	rule->AddQuotient(500);
	rule->AddQuotient(100);
	rule->AddQuotient(50);
	rule->AddQuotient(10);
	
	auto change = rule->CalculateByPolicy(350);

	EXPECT_EQ(change->ToString(), "100:3,50:1");
}