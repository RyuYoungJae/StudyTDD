#pragma once
#include "gtest/gtest.h"
#include "Account.h"

class AccountTests : public testing::Test
{
public:
	std::shared_ptr<Account> m_account;

protected:
	void SetUp() override
	{
		m_account = std::make_shared<Account>(10000);
	}
};