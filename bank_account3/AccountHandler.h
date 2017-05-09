#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"
#include "BoundCheckArray.h"

/*���� ���������� ó��*/
class AccountHandler
{
private:
	BoundCheckArray<Account*> accArr;  //�� �������� ������ ���� ����ü �迭
	int accNum;       //�� ���� ����

public:
	/* ������� ���� ���*/
	AccountHandler();
	~AccountHandler();
	void ShowMenu();       //�޴� ���
	void MakeAccount();    //���� ����
	void Deposit();        //�Ա�
	void Withdraw();       //���
	void ShowAllAccount(); //��ü�� �ܾ���ȸ

	void MakeNormalAccount();  //������� ����
	void MakeHighCreditAccount(); //�ſ���� ����
};

#endif
