#include "Account.h"
#include "BankingCommonDecl.h"

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

