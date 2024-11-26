#pragma once
#include <iostream>
#include "ClsBankClient.h"
#include "ClsScreen.h"
#include "ClsUtility.h"
#include <iomanip>
using namespace std;
class ClsTotalBalanceScreen:protected ClsScreen
{
	static void PrintClientsBalanceRecordLine(ClsBankClient client) {
		cout << "\t| " << setw(15) << left << client.AccountNumber();
		cout << "| " << setw(40) << left << client.FullName();
		cout << "| " << setw(12) << left << client.AccountBalance;


	}
public:
	static void ShowTotalBalance() {

		vector <ClsBankClient>vClients;
		vClients = ClsBankClient::GetClientList();
		string Title = "\t  Total balance screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") client(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;
		cout << "\t| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "BAlance";
		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;
		double TotalBalance = ClsBankClient::GetTotalBalance();
		if (vClients.size() == 0)
			cout << "\t\t\t\tNo CLient Available in the system!" << endl;
		else
			for (ClsBankClient& C : vClients) {
				PrintClientsBalanceRecordLine(C);
				cout << endl;
			}
		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;
		cout << "\t\t\t\t\t\t     Total Balance = " << TotalBalance << endl;
		cout << "\t\t\t\t\t\t     (" << ClsUtility::NumberToText(int(TotalBalance)) << ")" << endl;


	}
};

