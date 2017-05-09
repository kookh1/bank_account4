#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountException.h"

AccountHandler::AccountHandler() : accNum(0)
{}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}


/* 메뉴 출력*/
void AccountHandler::ShowMenu()
{
	cout << endl << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl << endl;
}

/* 계좌 개설 */
void AccountHandler::MakeAccount()
{
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;

	int choice;
	cout << "선택: ";
	cin >> choice;

	if (choice == NORMAL)
	{
		MakeNormalAccount();
	}
	else if (choice == CREDIT)
	{
		MakeHighCreditAccount();
	}
}


void  AccountHandler::MakeNormalAccount()  //보통계좌 개설
{
	cout << "[보통예금계좌 개설]" << endl;
	int accId;
	cout << "계좌ID: ";
	cin >> accId;

	String name;
	cout << "이름: ";
	cin >> name;

	int balance;
	cout << "입금액: ";
	cin >> balance;

	int ratio;
	cout << "이율: ";
	cin >> ratio;

	accArr[accNum++] = new NormalAccount(accId, name, balance, ratio);
}

void  AccountHandler::MakeHighCreditAccount() //신용신뢰계좌 개설
{
	cout << "[신용신뢰계좌 개설]" << endl;
	int accId;
	cout << "계좌ID: ";
	cin >> accId;

	String name;
	cout << "이름: ";
	cin >> name;

	int balance;
	cout << "입금액: ";
	cin >> balance;

	int ratio;
	cout << "이율: ";
	cin >> ratio;

	int level;
	cout << "신용등급(1toA, 2toB, 3toC): ";
	cin >> level;

	switch (level)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(accId, name, balance, ratio, LEVEL_A);
		break;

	case 2:
		accArr[accNum++] = new HighCreditAccount(accId, name, balance, ratio, LEVEL_B);
		break;

	case 3:
		accArr[accNum++] = new HighCreditAccount(accId, name, balance, ratio, LEVEL_C);
		break;
	}
}

/* 전체고객 잔액조회 */
void AccountHandler::ShowAllAccount()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccount();
		cout << endl;
	}
}

/* 입금 */
void AccountHandler::Deposit()
{
	cout << "[입 금]" << endl;

	int accId;
	cout << "계좌ID: ";
	cin >> accId;

	try
	{
		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->GetAccId() == accId)
			{
				int money;
				cout << "입금액: ";
				cin >> money;

				accArr[i]->SetMoney(money);
				cout << "입금완료" << endl;
				return;
			}
		}
		cout << "해당 ID가 존재하지 않습니다." << endl;
	}
	catch (MinusDepositException expt)
	{
		expt.ShowExceptionReason();
	}
}


/* 출금 */
void AccountHandler::Withdraw()
{
	cout << "[출 금]" << endl;

	int accId;
	cout << "계좌ID: ";
	cin >> accId;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == accId)
		{
			int money;
			cout << "출금액: ";
			cin >> money;

			if (accArr[i]->GetMoney(money) == -1)  //balance < money 경우 -1반환
			{
				cout << "잔액부족" << endl;
				return;
			}
			cout << "출금완료" << endl;
			return;
		}
	}
	cout << "해당 ID가 존재하지 않습니다." << endl;
}
