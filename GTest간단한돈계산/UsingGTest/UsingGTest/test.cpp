#include "pch.h"
#include "Money.h"
#include "Bank.h"

TEST(MoneyTests, Times_x2_Return2)
{
	auto usd = std::make_shared<Money>("usd", 1);
	
	auto result = usd->Times(2);
	auto expectation = std::make_shared<Money>("usd", 2);

	EXPECT_TRUE(expectation->Equal(result));
}

TEST(BankTests, Exchange_2chfTousd_1usd)
{
	auto bank = std::make_shared<Bank>();
	bank->AddRate("chf", "usd", 0.5);

	auto chf = std::make_shared<Money>("chf", 2);
	auto result = bank->Exchange(chf, "usd");
	auto expectaiton = std::make_unique<Money>("usd", 1);

	EXPECT_TRUE(expectaiton->Equal(result));
}