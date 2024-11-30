#pragma once
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ClsString.h"
#include "ClsPerson.h"

using namespace std;
class ClsUser:public ClsPerson
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1,AddNewMode=2};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permission;
	bool _MarkForDeleted = false;
	static ClsUser _GetEmptyObject() {
		return ClsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static ClsUser _ConvertLineToUserObject(string DataLine) {
		vector <string>vUser;
		vUser = ClsString::split(DataLine,"#//#");
		return ClsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4],vUser[5], stoi(vUser[6]));
	}
	static string _ConvertUserObjectToLine(ClsUser User,string separator = "#//#") {
		string UserLineRecord = "";
		UserLineRecord +=User.FirstName + separator;
		UserLineRecord +=User.LastName + separator;
		UserLineRecord +=User.Email + separator;
		UserLineRecord +=User.Phone + separator;
		UserLineRecord +=User.UserName + separator;
		UserLineRecord +=User.Password + separator;
		UserLineRecord +=to_string(User.Permission) + separator;
		return UserLineRecord;
	}
	static vector <ClsUser>_LoadDataFromFile() {
		vector<ClsUser>_vUsers;
		ifstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
				
			while (getline(MyFile,Line)) {
				ClsUser User = _ConvertLineToUserObject(Line);
				_vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _vUsers;
	}
	static void _SaveUsersDataToFile(vector <ClsUser> vUsers)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (ClsUser U : vUsers)
			{
				if (U.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}
	void _AddNewDataLineToFile(string DataLine) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);//read Mode
		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;

			MyFile.close();
		}
	}
	void _Update() {
		vector <ClsUser>_vUsers;
		_vUsers = _LoadDataFromFile();
		for (ClsUser& U : _vUsers) {
			if (U.UserName==UserName)
			{
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
	}
	void _AddNew() {
		_AddNewDataLineToFile(_ConvertUserObjectToLine(*this));
	}

public:
	enum enPermission{eAll=-1,pListCient=1,pAddClient=2,pDalateClient=4,
	pUpdateClient=8,pFindClient=16,pTransactions=32, pManageUsers=64
	};
	ClsUser(enMode Mode, string FirstNmae, string LastName, string Email,
		string Phone, string UserName, string Password, int Permmission)
		:ClsPerson(FirstNmae, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permission = Permmission;
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	bool MarkedForDeleted() {
		return _MarkForDeleted ;
	}

	void SetUserName(string UserName) {
		_UserName = UserName;
	}
	string GetUserName() {
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName))string UserName;
	void SetPassword(string Password) {
		_Password = Password;
	}
	string GetPassword() {
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword))string Password;
	void SetPermission(int Permission) {
		_Permission = Permission;
	}
	int GetPermission() {
		return _Permission;
	}
	__declspec(property(get = GetPermission, put = SetPermission))int Permission;

	static ClsUser Find(string UserName) {
		vector <ClsUser>vUsers;
		fstream Myfile;
		Myfile.open("Users.txt", ios::in);
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile,Line)) {
				ClsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName==UserName)
				{
					Myfile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			Myfile.close();
		}
		return _GetEmptyObject();

	}
	static ClsUser Find(string UserName,string Password) {
		vector <ClsUser>vUsers;
		fstream Myfile;
		Myfile.open("Users.txt", ios::in);
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line)) {
				ClsUser User = _ConvertLineToUserObject(Line);
				if ((User.UserName,User.Password) == (UserName,Password))
				{
					Myfile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			Myfile.close();
		}
		return _GetEmptyObject();

	}
	static bool IsUserExist(string UserName) {
		ClsUser User = ClsUser::Find(UserName);
		return (!User.IsEmpty());
	}
	bool Dalate() {
		vector<ClsUser>_vUsers;
		_vUsers = _LoadDataFromFile();
		for (ClsUser& U : _vUsers) {
			if (U.UserName==_UserName)
			{
				U._MarkForDeleted = true;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
		*this = _GetEmptyObject();
	}
	static ClsUser GetAddNewUserObject(string UserName) {
		return ClsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}
	static vector <ClsUser> GetUsersList() {
		return _LoadDataFromFile();
	}
	enum enSaveResuts{svFaildEmptyObject=0,svSucceeded=1,svFaildUserExist=2};
	enSaveResuts Save() {
		switch (_Mode)
		{
		case ClsUser::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResuts::svFaildEmptyObject;
			}
			break;
		}
		case ClsUser::UpdateMode:
		{
			_Update();
			return enSaveResuts::svSucceeded;
			break;
		}
		case ClsUser::AddNewMode:
		{
			if (ClsUser::IsUserExist(_UserName))
			{
				return enSaveResuts::svFaildUserExist;
			}
			else
			{
				_AddNew();
				//set the mode to update after add user
				_Mode = enMode::UpdateMode;
				return enSaveResuts::svSucceeded;
			}
			break;
		}
		default:
			break;
		}
	}
	
	//for test
	static void _PrintClient(ClsUser Client) {
		cout << "\nUser Card:";
		cout << "\n-------------------------";
		cout << "\nFirstName         : " << Client.FirstName;
		cout << "\nLastName          : " << Client.LastName;
		cout << "\nFullname          : " << Client.FullName();
		cout << "\nEmail             : " << Client.Email;
		cout << "\nPhone             : " << Client.Phone;
		cout << "\nUserNAme          : " << Client.UserName;
		cout << "\nPassword          : " << Client.Password;
		cout << "\n-------------------------\n";
	}
	void Print() {
		_PrintClient(*this);
	}
};

