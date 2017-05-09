#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

/*고객의 계좌정보*/
class Account
{
private:
	int accId;           //계좌ID
	char *name;          //고객 이름
	int balance;         //고객의 잔액

public:
	Account(int accId, char *name, int balance);
	Account(const Account &ref);
	~Account();

	int GetAccId() const; //계좌ID 반환
	virtual void SetMoney(int money) = 0;   //입금 
	int GetMoney(int money);   //출금
	virtual void ShowAccount() const = 0;  //계좌정보 보기
};

#endif
