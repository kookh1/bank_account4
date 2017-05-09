#include "Account.h"
#include "BankingCommonDecl.h"
#include "AccountException.h"

Account::Account(int accId, String name, int balance)
	: accId(accId), balance(balance)
{
	this->name = name;
}

int Account::GetAccId() const //����ID ��ȯ
{
	return accId;
}

void Account::SetMoney(int money) throw (MinusDepositException)  //�Ա� 
{
	if (money < 0)
	{
		MinusDepositException expt(money);
		throw expt;
	}

	this->balance += money;
}

int Account::GetMoney(int money)   //���
{
	if (money > this->balance)
		return -1;

	this->balance -= money;
	return this->balance;
}

void Account::ShowAccount() const  //�������� ����
{
	cout << "����ID: " << this->accId << endl;
	cout << "�̸�: " << this->name << endl;
	cout << "�ܾ�: " << this->balance << endl;
}

