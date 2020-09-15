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

TEST(VendingMachine, Pull_Coke_NotNull)
{
	auto machine = std::make_shared<VendingMachine>();
	machine->RegisterDrink(std::make_shared<Drink>("Coke", 600, 10));

	auto coke = machine->Push("Coke");

	EXPECT_TRUE(coke != nullptr);
}

TEST(VendingMachine, Pull_Total10Coke_Remain9)
{
	auto machine = std::make_shared<VendingMachine>();
	machine->RegisterDrink(std::make_shared<Drink>("Coke", 600, 10));

	machine->Push("Coke");

	EXPECT_EQ(machine->GetRemainCount("Coke"), 9);
}