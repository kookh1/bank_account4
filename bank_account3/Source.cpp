#include<iostream>
#include<cstring>
using namespace std;

/* 상수 정보 */
const int NAME_LEN = 20;  //고객의 이름길이

enum{MAKE=1, DEPOSIT, WITHDRAW, SHOW, EXIT}; //은행계좌 메뉴정보

/*고객의 계좌정보*/
class Account
{
private:
	int accId;           //계좌ID
	char *name;          //고객 이름
	int balance;         //고객의 잔액

public:
	Account(int accId, char *name, int balance)
		: accId(accId), balance(balance)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	
	~Account()
	{
		delete[] name;
	}

	int GetAccId()  //계좌ID 반환
	{
		return accId;
	}
	
	void SetMoney(int money)   //입금 
	{
		this->balance += money;
	}
	
	int GetMoney(int money)   //출금
	{
		if (money > this->balance)
			return -1;

		this->balance -= money;
		return this->balance;
	}

	void ShowAccount()   //계좌정보 보기
	{
		cout << "계좌ID: " << this->accId << endl;
		cout << "이름: " << this->name << endl;
		cout << "잔액: " << this->balance << endl << endl;
	}
};

Account *accArr[100];  //고객 계좌정보 저장을 위한 구조체 배열
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


	accArr[accNum++] = new Account(accId, name, balance);
}

/* 전체고객 잔액조회 */
void ShowAllAccount()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccount();
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
		if (accArr[i]->GetAccId() == accId)
		{
			int money;
			cout << "입금액: ";
			cin >> money;

			accArr[i]->SetMoney(money);
			return;
		}
	}
	cout << "해당 ID가 존재하지 않습니다." << endl;
}


/* 출금 */
void Withdraw()
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
		case MAKE:
			MakeAccount();   //계좌 개설
			break;
		case DEPOSIT:
			Deposit();       //입금
			break;
		case WITHDRAW:
			Withdraw();      //출금
			break;
		case SHOW:
			ShowAllAccount(); //모든 계좌정보 메뉴 출력
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++)
				delete accArr[i];
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
		
	}
	return 0;
}