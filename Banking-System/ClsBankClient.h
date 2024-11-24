#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ClsString.h"
#include "ClsPerson.h"
using namespace std;
class ClsBankClient:ClsPerson
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	static ClsBankClient _ConvertLineToClientOpject(string Line) {
		
		vector<string>vClientDate;
		vClientDate = ClsString::split(Line, "#//#");
		return ClsBankClient(enMode::UpdateMode, vClientDate[0], vClientDate[1], vClientDate[2],
			vClientDate[3], vClientDate[4], vClientDate[5], stod(vClientDate[6]));

		

	}
	static ClsBankClient _GetEmptyClientObject() {
		return ClsBankClient(enMode::EmptyMode, "", "", "", "", "", "",0);
	}
public:
	ClsBankClient(enMode Mode, string FirstName, string LastName, 
		string Email , string Phone, string AccountNumber,
		string PinCode, float AccountBalance):ClsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber() {
		return _AccountNumber;
	}

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(put = SetPinCode, get = GetPinCode))string PinCode;
	
	void SetAccountBalance(double AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(put = SetAccountBalance, get = GetAccountBalance))double AccountBalance;
	
	void print() {
		cout << "\nclient Card:";
		cout << "\n-------------------------";
		cout << "\nFirstName         : "<<FirstName;
		cout << "\nLastName          : "<<LastName;
		cout << "\nFullname          : "<<FullName();
		cout << "\nEmail             : "<<Email;
		cout << "\nPhone             : "<<Phone;
		cout << "\nAcc. Number       : "<<_AccountNumber;
		cout << "\nPassword          : "<<_PinCode;
		cout << "\nBalance           : "<<_AccountBalance;
		cout << "\n-------------------------\n";
	}

	 static ClsBankClient Find(string AccountNumber) {
		 vector <ClsBankClient>vClients;
		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::in);//read Mode
		 if (MyFile.is_open())
		 {
			 string Line;
			 while (getline(MyFile,Line))
			 {
				 ClsBankClient Client = _ConvertLineToClientOpject(Line);
				 if (Client.AccountNumber()==AccountNumber)
				 {
					 MyFile.close();
					 return Client;
				 }
				 vClients.push_back(Client);
			 }
			 MyFile.close();
		 }
		 return _GetEmptyClientObject();
	}

	 static ClsBankClient Find(string AccountNumber,string PinCode) {
		 vector <ClsBankClient>vClients;
		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::in);//read Mode
		 if (MyFile.is_open())
		 {
			 string Line;
			 while (getline(MyFile, Line))
			 {
				 ClsBankClient Client = _ConvertLineToClientOpject(Line);
				 if ((Client.AccountNumber(),Client.PinCode) == (AccountNumber,PinCode))
				 {
					 MyFile.close();
					 return Client;
				 }
				 vClients.push_back(Client);
			 }
			 MyFile.close();
		 }
		 return _GetEmptyClientObject();
	 }
	 static bool IsClientExist(string AccountNumber) {
		 ClsBankClient Client = ClsBankClient::Find(AccountNumber);
		 return (!Client.IsEmpty());
	 }

};

