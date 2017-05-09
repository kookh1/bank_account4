#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"
#include "BoundCheckArray.h"

/*고객의 계좌정보를 처리*/
class AccountHandler
{
private:
	BoundCheckArray<Account*> accArr;  //고객 계좌정보 저장을 위한 구조체 배열
	int accNum;       //고객 계좌 개수

public:
	/* 은행계좌 관리 기능*/
	AccountHandler();
	~AccountHandler();
	void ShowMenu();       //메뉴 출력
	void MakeAccount();    //계좌 개설
	void Deposit();        //입금
	void Withdraw();       //출금
	void ShowAllAccount(); //전체고객 잔액조회

	void MakeNormalAccount();  //보통계좌 개설
	void MakeHighCreditAccount(); //신용계좌 개설
};

#endif
