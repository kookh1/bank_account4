#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include "BankingCommonDecl.h"

class MinusDepositException
{
private:
	int reqDep;		// 요청 입금액
public:
	MinusDepositException(int money) : reqDep(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: " << reqDep << "는 입금불가]" << endl;
	}
};

class InsufficientBalanceException
{
private:
	int	balance;	// 잔고
public:
	InsufficientBalanceException(int money) : balance(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: 잔액 " << balance << ", 잔액부족]" << endl;
	}
};

#endif