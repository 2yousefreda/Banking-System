#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ClsString.h"
#include "ClsPerson.h"
#include "EncryptionKey.h"
using namespace std;
int EncryptionKey::_EncryptionKey = EncryptionKey::GetEncryptionKey();
class ClsBankClient:public ClsPerson 
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1, AddNewMode=2};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelete=false;
	static ClsBankClient _ConvertLineToClientOpject(string Line) {

		vector<string>vClientDate;
		vClientDate = ClsString::split(Line, "#//#");
		string AccountBalance = vClientDate[6];
		return ClsBankClient(enMode::UpdateMode, vClientDate[0],
			vClientDate[1],
			vClientDate[2],
			vClientDate[3],
			vClientDate[4],
			vClientDate[5],
			stod(AccountBalance)
		);



	}
	static string _ConvertClientObjectToLine(ClsBankClient Client, string separator = "#//#") {
		string ClientLineRecord = "";
		ClientLineRecord += Client.FirstName + separator;
		ClientLineRecord += Client.LastName + separator;
		ClientLineRecord += Client.Email + separator;
		ClientLineRecord += Client.Phone + separator;
		ClientLineRecord += Client.AccountNumber() + separator;
		ClientLineRecord += Client.PinCode + separator;
		ClientLineRecord += to_string(Client.AccountBalance) + separator;
		return ClientLineRecord;
	}
	static ClsBankClient _GetEmptyClientObject() {
		return ClsBankClient(enMode::EmptyMode, "", "", "", "", "", "",0);
	}
	static void _SaveClientDataToFile(vector<ClsBankClient> vClients) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//read Mode
		if (MyFile.is_open())
		{
			string DataLine;
			for (ClsBankClient C: vClients) {
				if (C.MarkedForDelete() == false)
				{
				DataLine = _ConvertClientObjectToLine(C);
				MyFile << DataLine<<endl;
				}
			}
			MyFile.close();
		}
	}
	static vector<ClsBankClient>_LoadDateFromFile() {
		vector<ClsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				ClsBankClient Client = _ConvertLineToClientOpject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	void _AddNewDataLineToFile(string DataLine) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out|ios::app);//read Mode
		if (MyFile.is_open())
		{
			MyFile << DataLine<<endl;
			
			MyFile.close();
		}
	}
	 void _Update() {
		vector<ClsBankClient> _vClients;
		_vClients = _LoadDateFromFile();
		for (ClsBankClient &c: _vClients)
		{
			if (c.AccountNumber() == AccountNumber())
			{
				c = *this;
				break;
			}
		}
	}
	 void _AddNew() {
		 _AddNewDataLineToFile(_ConvertClientObjectToLine(*this));
	 }
public:
	ClsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber,
		string PinCode, double AccountBalance): ClsPerson(FirstName, LastName, Email, Phone)
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

	double MarkedForDelete() {
		return _MarkForDelete;
	}

	
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
	 enum enSaveResult{ svFaildEmptyObject = 0, svSucceeded = 1 ,svFaildAccountNumberExist};
	 enSaveResult Save() {
		 switch (_Mode)
		 {
		 case ClsBankClient::EmptyMode:
			 if (IsEmpty())
			 {
			 return enSaveResult::svFaildEmptyObject;
			 }
			 break;
		 case ClsBankClient::UpdateMode:
			 _Update();
			 return enSaveResult::svSucceeded;
			 break;
		 case ClsBankClient::AddNewMode:
			 if (ClsBankClient::IsClientExist(_AccountNumber))
			 {
				 return enSaveResult::svFaildAccountNumberExist;
			 }
			 else
			 {
				 _AddNew();
				 _Mode = enMode::UpdateMode;
				 return enSaveResult::svSucceeded;
			 }
		 default:
			 break;
		 }
		 return enSaveResult::svFaildEmptyObject;
	 }

	 static bool IsClientExist(string AccountNumber) {
		 ClsBankClient Client = ClsBankClient::Find(AccountNumber);
		 return (!Client.IsEmpty());
	 }
	 static ClsBankClient GetAddNewClientObject(string AccountNumber) {
		 return ClsBankClient(enMode::AddNewMode,"","","","", AccountNumber,"",0);
	 }
	 bool Delete() {
		 vector<ClsBankClient>_vCleint;
		 _vCleint = _LoadDateFromFile();
		 for (ClsBankClient &C:_vCleint)
		 {
			 if (C.AccountNumber()==_AccountNumber)
			 {
				 C._MarkForDelete = true; 
				 break;
			 }
		 }
		 _SaveClientDataToFile(_vCleint);
		 *this = _GetEmptyClientObject();
	 return true;
	 }
	 static vector<ClsBankClient>GetClientList(){
		 return _LoadDateFromFile();
	 }
	 static double GetTotalBalance() {
		 vector<ClsBankClient>vClients=ClsBankClient::GetClientList();
		 double TotalBalance = 0;
		 for (ClsBankClient& C : vClients) {
			 TotalBalance += C.AccountBalance;
		 }
		 return TotalBalance;
	 }
};

