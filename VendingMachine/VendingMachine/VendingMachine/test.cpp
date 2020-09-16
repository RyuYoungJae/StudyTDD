#include "pch.h"
#include <memory.h>
#include "VendingMachine.h"
#include "Drink.h"

TEST(VendingMachine, RegisterDrink_Coke600wonN10) 
{
	auto machine = std::make_shared<VendingMachine>();
	machine->RegisterDrink(std::make_shared<Drink>("Coke", 600, 10));

	EXPECT_EQ(machine->ToString(), "Coke:600:10");
}

TEST(VendingMachine, PutMoney_1000_equal)
{
	auto machine = std::make_shared<VendingMachine>();
	machine->PutMoney(1000);

	EXPECT_EQ(machine->GetSavingMoney(), 1000);
}

TEST(VendingMachine, ReturnMoney_1000In_1000)
{
	auto machine = std::make_shared<VendingMachine>();
	machine->PutMoney(1000);
	auto money = machine->ReturnMoney();

	EXPECT_EQ(money, 1000);
}

TEST(VendingMachine, ReturnMoney_1000inN650Coke_Return350)
{
	auto machine = std::make_shared<VendingMachine>();
	machine->RegisterDrink(std::make_shared<Drink>("Coke", 650, 10));
	machine->PutMoney(1000);
	
	auto coke = machine->Push("Coke");
	auto change = machine->ReturnMoney();

	EXPECT_TRUE(coke != nullptr);
	EXPECT_EQ(change, 350);
}

TEST(VendingMachine, ReturnMoney_600inN650Coke_Return600)
{
	auto machine = std::make_shared<VendingMachine>();
	machine->RegisterDrink(std::make_shared<Drink>("Coke", 650, 10));
	machine->PutMoney(600);

	auto coke = machine->Push("Coke");
	auto change = machine->ReturnMoney();

	EXPECT_TRUE(coke == nullptr);
	EXPECT_EQ(change, 600);
}