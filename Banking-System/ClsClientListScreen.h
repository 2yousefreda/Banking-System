#pragma once
#include <iostream>
#include <iomanip>
#include "ClsBankClient.h"
using namespace std;
class ClsClientListScreen:protected ClsScreen
{
	static void PrintClientsResult(ClsBankClient client) {
		cout << "\t| " << setw(15) << left << client.AccountNumber();
		cout << "| " << setw(20) << left << client.FullName();
		cout << "| " << setw(12) << left << client.Phone;
		cout << "| " << setw(20) << left << client.Email;
		cout << "| " << setw(10) << left << client.PinCode;
		cout << "| " << setw(12) << left << client.AccountBalance;


	}
public:
	static void ShowClientsList() {
		if (!ChickAccessRights(ClsUser::enPermission::pListCient))
		{
			return;
		}
		vector <ClsBankClient>vClients;
		vClients = ClsBankClient::GetClientList();
		string Title = "\t  Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") client(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;

		cout << "\t| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "BAlance";

		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;
		if (vClients.size() == 0)
			cout << "\t\t\t\tNo CLient Available in the system!" << endl;
		else
			for (ClsBankClient& C : vClients) {
				PrintClientsResult(C);
				cout << endl;
			}
		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;

	}
};

