#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

/*보통 계좌정보*/
class NormalAccount : public Account
{
private:
	int ratio;   //이율
public:
	NormalAccount(int accId, char *name, int balance, int ratio)
		: Account(accId, name, balance), ratio(ratio)
	{}

	virtual void SetMoney(int money)
	{
		Account::SetMoney(money);   //입금액
		Account::SetMoney((int)money*(ratio / 100.0));  //입금액 * 이자
	}

	virtual void ShowAccount() const
	{
		Account::ShowAccount();
		cout << "이율: " << ratio << endl;
	}
};

#endif