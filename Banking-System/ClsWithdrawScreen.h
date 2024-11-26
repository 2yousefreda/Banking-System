#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "ClsBankClient.h"
using namespace std;

class ClsWithdrawScreen:protected ClsScreen
{
private:
	static string _ReadAccountNumber() {
		cout << "\n\n\nEnter Account Number: ";
		string AccountNumber = ClsInputValidate::ReadString();
		return AccountNumber;
	}
	static void _PrintClient(ClsBankClient Client) {
		cout << "\nclient Card:";
		cout << "\n-------------------------";
		cout << "\nFirstName         : " << Client.FirstName;
		cout << "\nLastName          : " << Client.LastName;
		cout << "\nFullname          : " << Client.FullName();
		cout << "\nEmail             : " << Client.Email;
		cout << "\nPhone             : " << Client.Phone;
		cout << "\nAcc. Number       : " << Client.AccountNumber();
		cout << "\nPassword          : " << Client.PinCode;
		cout << "\nBalance           : " << Client.AccountBalance;
		cout << "\n-------------------------\n";
	}
public:
	static void ShowWithdrawScreen() {
		_DrawScreenHeader("\tWithdraw Screen");
		string AccountNumber = _ReadAccountNumber();
		while (!ClsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client With [" << AccountNumber << "] is not Exist\n";
			AccountNumber = _ReadAccountNumber();
		}
		ClsBankClient Client = ClsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		double Amount = 0;
		cout << "Enter Withdraw amount : ";
		Amount = ClsInputValidate::ReadDoubleNumber();
		cout << "Are you sure want perform this transaction?(Y/N):  ";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			if (Client.Withdraw(Amount))
			{
			
			cout << "\n\tAmount Withdraw successfully ;)\n\n";
			cout << "New Balance is : " << Client.AccountBalance << endl;
				
			}
			else
			{
				cout << "\n\nYour balance isn't enogh to withdraw"<<endl;
				cout << "Amount to withdraw is : " << Amount<<endl;
				cout << "Your balance is: " << Client.AccountBalance<<endl;
			}
			
		}
		else
		{
			cout << "\n\tWithdraw Cancelled\n\n";
		}

	}
};

