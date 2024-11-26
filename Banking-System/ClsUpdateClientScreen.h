#pragma once
#include <iostream>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"
using namespace std;
class ClsUpdateClientScreen :protected ClsScreen
{
	static void _ReadClientInfo(ClsBankClient& Client) {
		cout << "Enter First Name: ";
		Client.FirstName = ClsInputValidate::ReadString();
		cout << "Enter Last Name : ";
		Client.LastName = ClsInputValidate::ReadString();
		cout << "Enter Email     : ";
		Client.Email = ClsInputValidate::ReadString();
		cout << "Enter Phone     : ";
		Client.Phone = ClsInputValidate::ReadString();
		cout << "Enter PinCode   : ";
		Client.PinCode = ClsInputValidate::ReadString();
		cout << "Enter Balance   : ";
		Client.AccountBalance = ClsInputValidate::ReadDoubleNumber();
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
	static void UpdateClient() {
		string Title = "\tUpdate Client Screen";
		_DrawScreenHeader(Title);
		string AccountNumber = "";
		cout << "\n\n\n\nenter Account Number : ";
		AccountNumber = ClsInputValidate::ReadString();
		while (!ClsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account not Exist please enter again\n";
			AccountNumber = ClsInputValidate::ReadString();
		}
		ClsBankClient Client = ClsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		cout << "\nAre you sure you want to update this client y/n";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			cout << "\n\nUpdate Client info:";
			cout << "\n-----------------------------\n";

			_ReadClientInfo(Client);
			ClsBankClient::enSaveResult SaveResult;
			SaveResult = Client.Save();
			switch (SaveResult)
			{
			case ClsBankClient::svSucceeded:
				cout << "\nAccount Update Successfully \n";
				_PrintClient(Client);
				break;
			case ClsBankClient::svFaildAccountNumberExist:
				cout << "\nError Account wasn't saved because Account Number Not Exist \n";
				break;
			case ClsBankClient::svFaildEmptyObject:
				cout << "\nError Account wasn't saved because it's Empty \n";
				break;
			default:
				break;
			}
		}

	}
};