#include "AccountHandler.h"
#include "BankingCommonDecl.h"


int main()
{
	AccountHandler manager;
	while (1)
	{
		manager.ShowMenu();   //메뉴 출력

		int choice;
		cout << "선택: ";
		cin >> choice;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();   //계좌 개설
			break;
		case DEPOSIT:
			manager.Deposit();       //입금
			break;
		case WITHDRAW:
			manager.Withdraw();      //출금
			break;
		case SHOW:
			manager.ShowAllAccount(); //모든 계좌정보 메뉴 출력
			break;
		case EXIT:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}

	}
	return 0;
}