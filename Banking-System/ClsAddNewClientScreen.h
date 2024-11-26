#pragma once
#include <iostream>
#include <iomanip>
#include "ClsInputValidate.h"
#include "ClsBankClient.h"
using namespace std;
class ClsAddNewClientScreen:protected ClsScreen
{
private:
	static void ReadClientInfo(ClsBankClient& Client) {
		cout << "Enter First Name: ";
		Client.FirstName = ClsInputValidate::ReadString();
		cout << "Enter Last Name: ";
		Client.LastName = ClsInputValidate::ReadString();
		cout << "Enter Email: ";
		Client.Email = ClsInputValidate::ReadString();
		cout << "Enter Phone: ";
		Client.Phone = ClsInputValidate::ReadString();
		cout << "Enter PinCode: ";
		Client.PinCode = ClsInputValidate::ReadString();
		cout << "Enter Balance: ";
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
	static void AddNewClient() {
		string Title = "\tAdd New Client Screen";
		ClsScreen::_DrawScreenHeader(Title);
		string AccounNumber = "";
		cout << "\n\n\n\nEnter AccountNumber: ";
		AccounNumber = ClsInputValidate::ReadString();
		while (ClsBankClient::IsClientExist(AccounNumber))
		{
			cout << "\nAccount Number Is Exist Please Enter Another One: ";
			AccounNumber = ClsInputValidate::ReadString();
		}
		ClsBankClient NewClient = ClsBankClient::GetAddNewClientObject(AccounNumber);
		ReadClientInfo(NewClient);
		ClsBankClient::enSaveResult Saveresult;
		Saveresult = NewClient.Save();
		system("cls");
		cout << "\tClient Added successfully!\n";
		_PrintClient(NewClient);

	}
};

