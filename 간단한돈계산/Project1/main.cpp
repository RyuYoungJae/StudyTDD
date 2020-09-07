#include <assert.h>
#include <memory>
#include "Money.h"
#include "Bank.h"

bool operator==(const std::shared_ptr<Money>& lhs, const std::shared_ptr<Money>& rhs)
{
	return lhs->GetCurrency() == rhs->GetCurrency()
		&& lhs->GetAmount() == rhs->GetAmount();
}

void TestUSDMultification(int value)
{
	auto usd = std::make_shared<Money>("usd", 1);
	auto usdP = usd->Times(2);

	assert(std::make_shared<Money>("usd", 2) == usdP);
}

void TestCHFMultification(int value)
{
	auto chf = std::make_shared<Money>("chf", 1);
	auto product = chf->Times(2);

	assert(std::make_shared<Money>("chf", 2) == product);
}

void TestExchangeCHFToUSD(int dallar)
{
	auto bank = std::make_shared<Bank>();
	bank->AddRate("chf", "usd", 0.5);

	auto chf = std::make_shared<Money>("chf", 2);
	auto currency = bank->Exchange(chf, "usd");

	assert(currency == std::make_shared<Money>("usd", 1));
}

void TestAddUsdToChf()
{
	auto usd = std::make_shared<Money>("usd", 2);
	auto chf = std::make_shared<Money>("chf", 2);

	auto bank = std::make_shared<Bank>();
	bank->AddRate("chf", "usd", 0.5);
	bank->AddRate("usd", "chf", 2);

	auto total = bank->Sum(usd, chf, "usd");

	assert(total == std::make_shared<Money>("usd", 3));
}

int main()
{
	TestUSDMultification(2);
	TestCHFMultification(2);
	TestExchangeCHFToUSD(2);
	TestAddUsdToChf();
}