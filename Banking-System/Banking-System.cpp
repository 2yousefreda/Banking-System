#include <iostream>
#include <iomanip>


#include "ClsDate.h"
#include "ClsInputValidate.h"
#include "ClsString.h"
#include "ClsUtility.h"
#include "ClsBankClient.h"
#include "ClsMainScreen.h"

using namespace std;




void PrintClientsBalanceRecordLine(ClsBankClient client) {
	cout << "| " << setw(15) << left << client.AccountNumber();
	cout << "| " << setw(40) << left << client.FullName();
	cout << "| " << setw(12) << left << client.AccountBalance;


}
void ShowTotalBalance() {

	vector <ClsBankClient>vClients;
	vClients = ClsBankClient::GetClientList();
	cout << "\n\t\t\t\t\tClients List (" << vClients.size() << ") client(s).";
	cout << "\n________________________________________________";
	cout << "__________________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "BAlance";
	cout << "\n________________________________________________";
	cout << "__________________________________________________\n" << endl;
	double TotalBalance = ClsBankClient::GetTotalBalance();
	if (vClients.size() == 0)
		cout << "\t\t\t\tNo CLient Available in the system!" << endl;
	else
		for (ClsBankClient& C : vClients) {
			PrintClientsBalanceRecordLine(C);
			cout << endl;
		}
	cout << "\n________________________________________________";
	cout << "__________________________________________________\n" << endl;
	cout << "\t\t\t\t\t     Total Balance = " << TotalBalance << endl;
	cout << "\t\t\t\t\t     (" << ClsUtility::NumberToText(int( TotalBalance))<<")" << endl;


}
int main()
{

	
	ClsMainScreen::ShowMainMenu();
	

}