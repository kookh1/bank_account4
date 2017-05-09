#ifndef HIGH_CREDIT_ACCOUNT_H__
#define HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

/*신용 계좌정보*/
class HighCreditAccount : public NormalAccount
{
private:
	int specialRatio;   //추가 이율
public:
	HighCreditAccount(int accId, String name, int balance, int ratio, int special)
		: NormalAccount(accId, name, balance, ratio), specialRatio(special)
	{}

	virtual void SetMoney(int money)
	{
		NormalAccount::SetMoney(money);   //입금액
		Account::SetMoney((int)money*(specialRatio / 100.0));  //입금액 * 이자
	}

	virtual void ShowAccount() const
	{
		NormalAccount::ShowAccount();
		cout << "추가이율: " << specialRatio << endl << endl;
	}
};

#endif