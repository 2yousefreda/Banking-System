#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ClsString.h"
#include "ClsPerson.h"
#include "Encryption_Decryption_Key.h"
#include "Global.h"
using namespace std;

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
		string AccountBalance = ClsUtility::Decryption(vClientDate[6], _DecryptionKey);

		return ClsBankClient(enMode::UpdateMode, ClsUtility::Decryption(vClientDate[0], _DecryptionKey),
			ClsUtility::Decryption(vClientDate[1], _DecryptionKey),
			ClsUtility::Decryption(vClientDate[2], _DecryptionKey),
			ClsUtility::Decryption(vClientDate[3], _DecryptionKey),
			ClsUtility::Decryption(vClientDate[4], _DecryptionKey),
			ClsUtility::Decryption(vClientDate[5], _DecryptionKey),
			stod(AccountBalance)
		);
	
	
	
	}
	static string _ConvertClientObjectToLine(ClsBankClient Client, string separator = "#//#") {
		string ClientLineRecord = "";
		ClientLineRecord += ClsUtility::Encryption(Client.FirstName, _EncryptionKey) + separator;
		ClientLineRecord += ClsUtility::Encryption(Client.LastName, _EncryptionKey) + separator;
		ClientLineRecord += ClsUtility::Encryption(Client.Email, _EncryptionKey) + separator;
		ClientLineRecord += ClsUtility::Encryption(Client.Phone, _EncryptionKey) + separator;
		ClientLineRecord += ClsUtility::Encryption(Client.AccountNumber(), _EncryptionKey) + separator;
		ClientLineRecord += ClsUtility::Encryption(Client.PinCode, _EncryptionKey) + separator;
		ClientLineRecord += ClsUtility::Encryption(to_string(Client.AccountBalance), _EncryptionKey);
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
	 string _PrepareTransferLogRecord(float Amount ,ClsBankClient DestinationClient,string UserName,string separator="#//#") {
		 string DataLine = "";
		 DataLine += ClsDate::GetSystemDateTimeString()+separator;
		 DataLine += AccountNumber()+separator;
		 DataLine += DestinationClient.AccountNumber() + separator;
		 DataLine += to_string(Amount) + separator;
		 DataLine += to_string(AccountBalance) + separator;
		 DataLine += to_string(DestinationClient.AccountBalance) + separator;
		 DataLine +=UserName ;
		 return DataLine;
		 

	 }
	 void _RegisterTransferLog(float Amount,ClsBankClient DestinationClient,string UserName) {
		 string DataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);
		 fstream MyFile;
		 MyFile.open("TransferLog.txt", ios::out | ios::app);
		 if (MyFile.is_open())
		 {
			 MyFile << DataLine << endl;
			 MyFile.close();
		 }
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
	struct  StTransferLogData
	{
		string Date;
		string sAcct;
		string dAcct;
		float Amount;
		float sBalance;
		float dBalance;
		string UserName;
	};
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
	 bool Transfer(float Amount , ClsBankClient&DestinationClient) {
		 if (Amount>AccountBalance)
		 {
			 return false;
		 }
		 Withdraw(Amount);
		 DestinationClient.Depoist(Amount);
		 _RegisterTransferLog(Amount, DestinationClient, CurrentUser.UserName);
		 return true;
	 }
	 static StTransferLogData ConvertDataLineToTransferData(string DataLine,string separator="#//#") {
		 vector <string>vTransferData;
		 vTransferData = ClsString::split(DataLine, separator);
		 StTransferLogData Data;
		 Data.Date = vTransferData[0];
		 Data.sAcct = vTransferData[1];
		 Data.dAcct = vTransferData[2];
		 Data.Amount = stod(vTransferData[3]);
		 Data.sBalance = stod(vTransferData[4]);
		 Data.dBalance = stod(vTransferData[5]);
		 Data.UserName = vTransferData[6];
		 return Data;
	 }
	 static vector<StTransferLogData>GetTransferLogList() {
		 vector<StTransferLogData> vTransferLog;
		 fstream MyFile;
		 MyFile.open("TransferLog.txt", ios::in);
		 if (MyFile.is_open())
		 {
			 string DataLine ;
			 while (getline(MyFile, DataLine))
			 {
				 StTransferLogData TransferData = ConvertDataLineToTransferData(DataLine);
				 vTransferLog.push_back(TransferData);
			 }
			 MyFile.close();
		 }
		 return vTransferLog;
	 }
};

