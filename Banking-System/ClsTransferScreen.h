#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "ClsBankClient.h"
using namespace std;
class ClsTransferScreen:protected ClsScreen
{
	static string _ReadAccountNumber(string Message) {
		string AccountNumber;
		cout << "\n\nEnter Account Number that you want transfer "<< Message<<": ";
		 AccountNumber=ClsInputValidate::ReadString();
		while (!ClsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n This Account Is Not Exist, Enter Another One: ";
			AccountNumber = ClsInputValidate::ReadString();
		}
		return AccountNumber;
	}
	static void _PrintClient(ClsBankClient Client) {
		cout << "\nclient Card:";
		cout << "\n-------------------------";
		cout << "\nFullname          : " << Client.FullName();
		cout << "\nAcc. Number       : " << Client.AccountNumber();
		cout << "\nBalance           : " << Client.AccountBalance;
		cout << "\n-------------------------\n";
	}
	static double ReadAmount(ClsBankClient SourceClient) {
		double Amount;
		cout << "\nEnter Amount that you want to transfer: ";
		Amount = ClsInputValidate::ReadDoubleNumber();
		while (Amount > SourceClient.AccountBalance) {
			cout << "\nAmount Exceeds the available Blance , Enter Anothe Amount : ";
			Amount = ClsInputValidate::ReadDoubleNumber();
		}
		return Amount;

	}
public:
	static void ShowTransferScreen() {
		string Title="\t    Transfer Screen";
		_DrawScreenHeader(Title);

		ClsBankClient SourceClient = ClsBankClient::Find(_ReadAccountNumber("From"));
		
		_PrintClient(SourceClient);
	
		ClsBankClient DestinationClinet = ClsBankClient::Find(_ReadAccountNumber("To"));
		_PrintClient(DestinationClinet);
		cout << "\n\nEnter The Amount That You need to transfer : ";
		double Amount = ReadAmount(SourceClient);
		cout << "\nAre you sure want to transform this opration?(Y/N):  ";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer)=='Y')
		{
			if (SourceClient.Transfer(Amount,DestinationClinet))
			{
				cout << "\nTransfer done successfully\n";

			}
			else {
				cout << "\nTransfer Faild \n";
			}
		}
		else
		{
			cout << "\nTransfer is canceld\n";
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClinet);
		
	
	}
};