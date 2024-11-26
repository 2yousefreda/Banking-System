#pragma once
#include <iostream>
#include "ClsBankClient.h"
#include "ClsScreen.h"
#include "ClsInputValidate.h"
using namespace std;
class ClsFindClientScreen:protected ClsScreen
{
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
	static void FindClientScreen() {
		string Title = "\tFind Client Screen";
		_DrawScreenHeader(Title);
		string AccountNumber;
		cout << "\n\n\n\nPlease Enter Account Number:  ";
		AccountNumber = ClsInputValidate::ReadString();
		while (!ClsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Not Exist Enter Anothe One: ";
			AccountNumber = ClsInputValidate::ReadString();
		}
		ClsBankClient Client = ClsBankClient::Find(AccountNumber);
		if (!Client.IsEmpty())
		{
			cout << "Client Found: \n";
		_PrintClient(Client);

		}
		else
		{
			cout << "Client Not Exist"<<endl;
		}
	}
};

