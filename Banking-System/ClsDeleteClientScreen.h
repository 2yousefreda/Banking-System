#pragma once
#include <iostream>
#include <iomanip>
#include "ClsBankClient.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"
using namespace std;
class ClsDeleteClientScreen :protected ClsScreen
{
public:
	static void DalateClinet() {
		string Title = "Delete Client Secreen";
		_DrawScreenHeader(Title);
		string AccounNumber = "";
		cout << "\nPlease Enter Accoun Number: ";
		AccounNumber = ClsInputValidate::ReadString();
		while (!ClsBankClient::IsClientExist(AccounNumber))
		{
			cout << "\nAccount Number is not Found, Chose Another One: ";
			AccounNumber = ClsInputValidate::ReadString();

		}
		ClsBankClient Client = ClsBankClient::Find(AccounNumber);
		Client.print();
		cout << "\nAre you sere you want to delete this Client (Y/N)? : ";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			if (Client.Delete())
			{
				cout << "\nClient Deleted successfully \n";
				Client.print();
			}
			else
			{
				cout << "\nError Client wasn't Deleted\n";
			}
		}
	}
};

