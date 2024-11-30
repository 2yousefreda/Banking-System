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
		string AccountBalance = ClsUtility::Decryption(vClientDate[6], EncryptionKey::GetDecryptionKey());

		return ClsBankClient(enMode::UpdateMode, ClsUtility::Decryption(vClientDate[0], EncryptionKey::GetDecryptionKey()),
			ClsUtility::Decryption(vClientDate[1], EncryptionKey::GetDecryptionKey()),
			ClsUtility::Decryption(vClientDate[2], EncryptionKey::GetDecryptionKey()),
			ClsUtility::Decryption(vClientDate[3], EncryptionKey::GetDecryptionKey()),
			ClsUtility::Decryption(vClientDate[4], EncryptionKey::GetDecryptionKey()),
			ClsUtility::Decryption(vClientDate[5], EncryptionKey::GetDecryptionKey()),
			stod(AccountBalance)
		);
	
	
	
	}
	static string _ConvertClientObjectToLine(ClsBankClient Client, string separator = "#//#") {
		string ClientLineRecord = "";
		ClientLineRecord += ClsUtility::Encryption(Client.FirstName, EncryptionKey::GetEncryptionKey()) + separator;
		ClientLineRecord += ClsUtility::Encryption(Client.LastName, EncryptionKey::GetEncryptionKey()) + separator;
		ClientLineRecord += ClsUtility::Encryption(Client.Email, EncryptionKey::GetEncryptionKey()) + separator;
		ClientLineRecord += ClsUtility::Encryption(Client.Phone, EncryptionKey::GetEncryptionKey()) + separator;
		ClientLineRecord += ClsUtility::Encryption(Client.AccountNumber(), EncryptionKey::GetEncryptionKey()) + separator;
		ClientLineRecord += ClsUtility::Encryption(Client.PinCode, EncryptionKey::GetEncryptionKey()) + separator;
		ClientLineRecord += ClsUtility::Encryption(to_string(Client.AccountBalance), EncryptionKey::GetEncryptionKey());
		return ClientLineRecord;
	}
	static ClsBankClient _GetEmptyClientObject() {
		return ClsBankClient(enMode::EmptyMode, "", "", "", "", "", "",0);
	}
	static void _SaveClientDataToFile(vector<ClsBankClient> vClients) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//write
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
				_SaveClientDataToFile(_vClients);
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

	bool MarkedForDelete() {
		return _MarkForDelete;
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
	 enum enSaveResult{  svSucceeded = 1 ,svFaildAccountNumberExist=2,svFaildEmptyObject = 3};
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
	 void Depoist(double Amount) {
		 _AccountBalance += Amount;
		 Save();
	 }
	 bool Withdraw(double Amount) {
		 if (Amount>_AccountBalance)
		 {
			 return false;
		 }
		 else
		 {
		 _AccountBalance -= Amount;
		 Save();
		 }
		 return true;
	 }
};

