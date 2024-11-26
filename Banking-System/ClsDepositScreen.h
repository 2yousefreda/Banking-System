#pragma once
#include <iostream>
#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "ClsBankClient.h"

using namespace std;
class ClsDepositScreen:protected ClsScreen
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
	static void ShowDepositScreen() {
		_DrawScreenHeader("\tDepoist Screen");
		string AccountNumber = _ReadAccountNumber();
		while (!ClsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client With [" << AccountNumber << "] is not Exist\n";
			AccountNumber = _ReadAccountNumber();
		}
		ClsBankClient Client= ClsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		double Amount = 0;
		cout << "Enter depoist amount : ";
		Amount = ClsInputValidate::ReadDoubleNumber();
		cout << "Are you sure want perform this transaction?(Y/N):  ";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer)=='Y')
		{
			Client.Depoist(Amount);
			cout << "\n\tAmount deposit successfully ;)";
			cout << "New Balance is : " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "\n\tDeposit Cancelled\n\n";
		}

	}
	
};

