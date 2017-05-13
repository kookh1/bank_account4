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


/* �޴� ���*/
void AccountHandler::ShowMenu()
{
	cout << endl << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl << endl;
}

/* ���� ���� */
void AccountHandler::MakeAccount()
{
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;

	int choice;
	cout << "����: ";
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


void  AccountHandler::MakeNormalAccount()  //������� ����
{
	cout << "[���뿹�ݰ��� ����]" << endl;
	int accId;
	cout << "����ID: ";
	cin >> accId;

	String name;
	cout << "�̸�: ";
	cin >> name;

	int balance;
	cout << "�Աݾ�: ";
	cin >> balance;

	int ratio;
	cout << "����: ";
	cin >> ratio;

	accArr[accNum++] = new NormalAccount(accId, name, balance, ratio);
}

void  AccountHandler::MakeHighCreditAccount() //�ſ�ŷڰ��� ����
{
	cout << "[�ſ�ŷڰ��� ����]" << endl;
	int accId;
	cout << "����ID: ";
	cin >> accId;

	String name;
	cout << "�̸�: ";
	cin >> name;

	int balance;
	cout << "�Աݾ�: ";
	cin >> balance;

	int ratio;
	cout << "����: ";
	cin >> ratio;

	int level;
	cout << "�ſ���(1toA, 2toB, 3toC): ";
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

/* ��ü�� �ܾ���ȸ */
void AccountHandler::ShowAllAccount()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccount();
		cout << endl;
	}
}

/* �Ա� */
void AccountHandler::Deposit()
{
	cout << "[�� ��]" << endl;

	int accId;
	cout << "����ID: ";
	cin >> accId;

	while (true)
	{
		try
		{
			for (int i = 0; i < accNum; i++)
			{
				if (accArr[i]->GetAccId() == accId)
				{
					int money;
					cout << "�Աݾ�: ";
					cin >> money;

					accArr[i]->SetMoney(money);
					cout << "�ԱݿϷ�" << endl;
					return;
				}
			}
			cout << "�ش� ID�� �������� �ʽ��ϴ�." << endl;
		}
		catch (MinusDepositException expt)
		{
			expt.ShowExceptionReason();
		}
	}
}


/* ��� */
void AccountHandler::Withdraw()
{
	cout << "[�� ��]" << endl;

	int accId;
	cout << "����ID: ";
	cin >> accId;

	while (true)
	{
		try
		{
			for (int i = 0; i < accNum; i++)
			{
				if (accArr[i]->GetAccId() == accId)
				{
					int money;
					cout << "��ݾ�: ";
					cin >> money;

					accArr[i]->GetMoney(money);
					cout << "��ݿϷ�" << endl;
					return;
				}
			}
			cout << "�ش� ID�� �������� �ʽ��ϴ�." << endl;
		}
		catch (MinusDepositException expt)
		{
			expt.ShowExceptionReason();
		}
		catch (InsufficientBalanceException expt)
		{
			expt.ShowExceptionReason();
		}
	}
}
