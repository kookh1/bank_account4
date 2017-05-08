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