#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include "BankingCommonDecl.h"

class MinusDepositException
{
private:
	int reqDep;		// ��û �Աݾ�
public:
	MinusDepositException(int money) : reqDep(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[���� �޽���: " << reqDep << "�� �ԱݺҰ�]" << endl;
		cout << "�ٽ� �Է����ּ���." << endl << endl;
	}
};

class InsufficientBalanceException
{
private:
	int	balance;	// �ܰ�
public:
	InsufficientBalanceException(int money) : balance(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[���� �޽���: �ܾ� " << balance << ", �ܾ׺���]" << endl;
		cout << "�ٽ� �Է����ּ���." << endl << endl;
	}
};

#endif