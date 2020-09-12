#include "pch.h"
#include "AccountTests.h"

TEST_F(AccountTests, GetBalance_CreateAccountHas10000_EQ10000)
{
	auto account = std::make_shared<Account>(10000);
	EXPECT_EQ(account->GetBalance(), 10000);
}

TEST_F(AccountTests, Deposit_Create10000NDeposit1000_Total11000)
{
	auto account = std::make_shared<Account>(10000);
	account->Deposit(1000);
	EXPECT_EQ(account->GetBalance(), 11000);
}

TEST_F(AccountTests, Deposit_Create10000NDepositMinus_10000)
{
	auto account = std::make_shared<Account>(10000);
	account->Deposit(-1000);
	EXPECT_EQ(account->GetBalance(), 10000);
}

TEST_F(AccountTests, Deposit_Create10000NDeposit0_10000)
{
	auto account = std::make_shared<Account>(10000);
	account->Deposit(0);
	EXPECT_EQ(account->GetBalance(), 10000);
}

TEST_F(AccountTests, Withdraw_Create10000NWithdraw1000_Total9000)
{
	auto account = std::make_shared<Account>(10000);
	account->Withdraw(1000);
	EXPECT_EQ(account->GetBalance(), 9000);
}

TEST_F(AccountTests, Withdraw_Create10000NWithdraw11000_10000)
{
	auto account = std::make_shared<Account>(10000);
	account->Withdraw(11000);
	EXPECT_EQ(account->GetBalance(), 10000);
}