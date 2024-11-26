#include <iostream>
#include <iomanip>


#include "ClsDate.h"
#include "ClsInputValidate.h"
#include "ClsString.h"
#include "ClsUtility.h"
#include "ClsBankClient.h"
#include "ClsMainScreen.h"

using namespace std;
void ReadClientInfo(ClsBankClient& Client) {
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
void UpdateClient() {
	string AccountNumber = "";
	cout << "\nenter Account Number : ";
	AccountNumber = ClsInputValidate::ReadString();
	while (!ClsBankClient::IsClientExist(AccountNumber))
	{
		cout << "Account not Exist please enter again\n";
		AccountNumber = ClsInputValidate::ReadString();
	}
	ClsBankClient Client = ClsBankClient::Find(AccountNumber);
	Client.print();
	cout << "\n\nUpdate Client info:";
	cout << "\n-----------------------------";
	ReadClientInfo(Client);
	ClsBankClient::enSaveResult SaveResult;
	SaveResult = Client.Save();
	switch (SaveResult)
	{
	case ClsBankClient::svFaildEmptyObject:
		cout << "\nAccount Update Successfully \n";
		Client.print();
		break;
	case ClsBankClient::svSucceeded:
		cout << "\nError Account wasn't saved because it's Empty \n";
		break;
	default:
		break;
	}

}

void AddNewClient() {
	string AccounNumber = "";
	cout << "\nEnter AccountNumber: ";
	AccounNumber = ClsInputValidate::ReadString();
	while (ClsBankClient::IsClientExist(AccounNumber))
	{
		cout << "\nAccount Number Is Exist Please Enter Another One: ";
			AccounNumber = ClsInputValidate::ReadString();
	}
	ClsBankClient NewClient=ClsBankClient::GetAddNewClientObject(AccounNumber);
	ReadClientInfo(NewClient);
	ClsBankClient::enSaveResult Saveresult;
	Saveresult = NewClient.Save();
	system("cls");
	cout << "\tClient Added successfully!\n";
	NewClient.print();

}

void DalateClinet() {
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
	if (toupper(Answer)=='Y')
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

void PrintClientsResult(ClsBankClient client) {
	cout << "| " << setw(15) << left << client.AccountNumber();
	cout << "| " << setw(20) << left << client.FullName();
	cout << "| " << setw(12) << left << client.Phone;
	cout << "| " << setw(20) << left << client.Email;
	cout << "| " << setw(10) << left << client.PinCode;
	cout << "| " << setw(12) << left << client.AccountBalance;


}
void ShowClientsList() {

	vector <ClsBankClient>vClients;
	vClients = ClsBankClient::GetClientList();
	cout << "\n\t\t\t\t\tClients List (" << vClients.size() << ") client(s).";
	cout << "\n________________________________________________";
	cout << "__________________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(12) << "phone";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(12) << "BAlance";

	cout << "\n________________________________________________";
	cout << "__________________________________________________\n" << endl;
	if (vClients.size() ==0 )
		cout << "\t\t\t\tNo CLient Available in the system!"<<endl;
	else
	for (ClsBankClient& C : vClients) {
		PrintClientsResult(C);
		cout << endl;
	}
	cout << "\n________________________________________________";
	cout << "__________________________________________________\n" << endl;

}
	
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
	cout << "\t\t\t\t\t     (" << ClsUtility::NumberToText(TotalBalance)<<")" << endl;


}
int main()
{

	
	ClsMainScreen::ShowMainMenu();
	

}