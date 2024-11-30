#pragma once
#include <iostream>
#include <iomanip>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"
using namespace std;
class ClsDeleteClientScreen :protected ClsScreen
{
private:
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
	static void DalateClinet() {
		string Title = "\tDelete Client Secreen";
		_DrawScreenHeader(Title);
		string AccounNumber = "";
		cout << "\n\n\n\nPlease Enter Accoun Number: ";
		AccounNumber = ClsInputValidate::ReadString();
		while (!ClsBankClient::IsClientExist(AccounNumber))
		{
			cout << "\nAccount Number is not Found, Chose Another One: ";
			AccounNumber = ClsInputValidate::ReadString();

		}
		ClsBankClient Client = ClsBankClient::Find(AccounNumber);
		_PrintClient(Client);
		cout << "\nAre you sere you want to delete this Client (Y/N)? : ";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			if (Client.Delete())
			{
				cout << "\nClient Deleted successfully \n";
				_PrintClient(Client);
			}
			else
			{
				cout << "\nClient wasn't Deleted\n";
			}
		}
	}
};

