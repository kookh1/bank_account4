#include<iostream>
#include<cstring>
using namespace std;

/* 상수 정보 */
const int NAME_LEN = 20;  //고객의 이름길이

enum{MAKE=1, DEPOSIT, WITHDRAW, SHOW, EXIT}; //은행계좌 메뉴정보

enum{NORMAL=1, CREDIT};   //계좌종류 정보 

enum{LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};  //신용신뢰 등급 별 이자율 정보


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
	virtual void SetMoney(int money)=0;   //입금 
	int GetMoney(int money);   //출금
	virtual void ShowAccount() const = 0;  //계좌정보 보기
};

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

/*신용 계좌정보*/
class HighCreditAccount : public NormalAccount
{
private:
	int specialRatio;   //추가 이율
public:
	HighCreditAccount(int accId, char *name, int balance, int ratio, int special)
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


Account::Account(int accId, char *name, int balance)
	: accId(accId), balance(balance)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(const Account &ref)   //복사 생성자
	: accId(ref.accId), balance(ref.balance)
{
	this->name = new char[strlen(ref.name) + 1];
	strcpy(this->name, ref.name);
}

Account::~Account()
{
	delete[] name;
}

int Account::GetAccId() const //계좌ID 반환
{
	return accId;
}

void Account::SetMoney(int money)   //입금 
{
	this->balance += money;
}

int Account::GetMoney(int money)   //출금
{
	if (money > this->balance)
		return -1;

	this->balance -= money;
	return this->balance;
}

void Account::ShowAccount() const  //계좌정보 보기
{
	cout << "계좌ID: " << this->accId << endl;
	cout << "이름: " << this->name << endl;
	cout << "잔액: " << this->balance << endl;
}


/*고객의 계좌정보를 처리*/

class AccountHandler
{
private:
	Account *accArr[100];  //고객 계좌정보 저장을 위한 구조체 배열
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
	cout <<endl<< "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl<<endl;
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

	char name[NAME_LEN];
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

	char name[NAME_LEN];
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

	switch(level)
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