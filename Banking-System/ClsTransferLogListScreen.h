#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "ClsString.h"
#include "ClsBankClient.h"
#include "ClsScreen.h"
using namespace std;
class ClsTransferLogListScreen :protected ClsScreen
{
	static void _PrintTransferData(ClsBankClient::StTransferLogData Transfer) {
		cout << setw(8) << left << "" << "| " << left << setw(20) << Transfer.Date;
		cout << "| " << left << setw(10) << Transfer.sAcct;
		cout << "| " << left << setw(10) << Transfer.dAcct;
		cout << "| " << left << setw(10) << Transfer.Amount;
		cout << "| " << left << setw(10) << Transfer.sBalance;
		cout << "| " << left << setw(10) << Transfer.dBalance;
		cout << "| " << left << setw(10) << Transfer.UserName;
	}

public:
	static void ShowTransferLogList() {

		vector <ClsBankClient::StTransferLogData> vTLog= ClsBankClient::GetTransferLogList();
		
		string Title = "\t  Login Register List Screen";
		string SubTitle = "\t    (" + to_string(vTLog.size()) + ") User(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(20) << "Date";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(10) << "UserName";


		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;
		if (vTLog.size() == 0)
			cout << "\t\t\t\tNo Login Register Available in the system!" << endl;
		else
			for (ClsBankClient::StTransferLogData& R : vTLog) {
				_PrintTransferData(R);
				cout << endl;
			}
		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;

	}
};

