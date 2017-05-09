#include<iostream>
using namespace std;

/* 상수 정보 */
const int NAME_LEN = 20;  //고객의 이름길이


/*고객의 계좌정보*/
struct Account
{
	int accId;           //계좌ID
	char name[NAME_LEN]; //고객 이름
	int balance;         //고객의 잔액
};

Account accArr[100];  //고객 계좌정보 저장을 위한 구조체 배열
int accNum = 0;       //고객 계좌 개수

/* 은행계좌 관리 기능*/
void ShowMenu();       //메뉴 출력
void MakeAccount();    //계좌 개설
void Deposit();        //입금
void Withdraw();       //출금
void ShowAllAccount(); //전체고객 잔액조회


/* 메뉴 출력*/
void ShowMenu()
{
	cout <<endl<< "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl<<endl;
}

/* 계좌 개설 */
void MakeAccount()
{
	cout << "[계좌개설]" << endl;
	
	int accId;
	cout << "계좌ID: ";
	cin >> accId;

	char name[NAME_LEN];
	cout << "이름: ";
	cin >> name;

	int balance;
	cout << "입금액: ";
	cin >> balance;

	accArr[accNum].accId = accId;
	strcpy_s(accArr[accNum].name, name);
	accArr[accNum].balance = balance;
	accNum += 1;
}

/* 전체고객 잔액조회 */
void ShowAllAccount()
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌ID: " << accArr[i].accId << endl;
		cout << "이름: " << accArr[i].name << endl;
		cout << "잔액: " << accArr[i].balance << endl<<endl;
	}
}

/* 입금 */
void Deposit()
{
	cout << "[입 금]" << endl;

	int accId;
	cout << "계좌ID: ";
	cin >> accId;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accId == accId)
		{
			int money;
			cout << "입금액: ";
			cin >> money;

			accArr[i].balance += money;
			return;
		}
	}
	cout << "해당 ID가 존재하지 않습니다." << endl;
}

int main()
{
	while (1)
	{
		ShowMenu();   //메뉴 출력

		int choice;
		cout << "선택: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			MakeAccount();
			break;
		case 2:
			Deposit();
			break;
		case 4:
			ShowAllAccount();
			break;
		case 5:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
		
	}


	return 0;
}