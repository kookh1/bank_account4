#include<iostream>
using namespace std;

/* 상수 정보 */
const int NAME_LEN = 20;  //고객의 이름길이


/*고객의 계좌정보*/
struct Account
{
	int accId;     //계좌ID
	char name[NAME_LEN]; //고객 이름
	int balance;   //고객의 잔액
};

Account accArr[100];  //고객 계좌정보 저장을 위한 구조체 배열

int main()
{
	
	return 0;
}