#pragma once
#include <iostream>
#include "ClsBankClient.h"
#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "ClsUser.h"
using namespace std;
class ClsUpdateUserScreen :protected ClsScreen
{
	static void _ReadUserInfo(ClsUser& User) {
		cout << "Enter First Name: ";
		User.FirstName = ClsInputValidate::ReadString();
		cout << "Enter Last Name: ";
		User.LastName = ClsInputValidate::ReadString();
		cout << "Enter Email: ";
		User.Email = ClsInputValidate::ReadString();
		cout << "Enter Phone: ";
		User.Phone = ClsInputValidate::ReadString();
		cout << "Enter Password: ";
		User.Password = ClsInputValidate::ReadString();
		User.Permission = _ReadPermissionToSet();
	}
	static int _ReadPermissionToSet() {
		int permission = 0;
		char Answer = 'n';
		cout << "\n\nPermission:\n";
		cout << "Do you need to give Full Access (Y/N)";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			return -1;
		}
		cout << "Do you Give Access To :\n";
		cout << " show Client list (Y/N): ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			permission += ClsUser::enPermission::pListCient;
		}
		cout << "Add New Client(Y/N): ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			permission += ClsUser::enPermission::pAddClient;
		}
		cout << "Delete Client(Y/N): ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			permission += ClsUser::enPermission::pDalateClient;
		}
		cout << "Update Client(Y/N): ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			permission += ClsUser::enPermission::pUpdateClient;
		}
		cout << "find Client(Y/N): ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			permission += ClsUser::enPermission::pFindClient;
		}
		cout << "TranceAction Menu(Y/N): ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			permission += ClsUser::enPermission::pTransactions;
		}
		cout << "Manage Users(Y/N): ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			permission += ClsUser::enPermission::pManageUsers;
		}
		cout << "Login Register(Y/N): ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			permission += ClsUser::enPermission::pLoginRegistrationList;
		}
		cout << "Currency Exchange(Y/N): ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			permission += ClsUser::enPermission::pCurrencyExchange;
		}
		return permission;
	}
	static void _PrintUser(ClsUser User) {
		cout << "\nUser Card:";
		cout << "\n-------------------------";
		cout << "\nUserName          : " << User.UserName;
		cout << "\nFirstName         : " << User.FirstName;
		cout << "\nLastName          : " << User.LastName;
		cout << "\nFullname          : " << User.FullName();
		cout << "\nEmail             : " << User.Email;
		cout << "\nPhone             : " << User.Phone;
		cout << "\nPassword          : " << User.Password;
		cout << "\nPermission        : " << User.Permission;

		cout << "\n-------------------------\n";
	}

public:
	static void ShowUpdateUserScreen() {
		string Title = "\t   Update User Screen";
		_DrawScreenHeader(Title);

		string UserName ;
		cout << "\nEnter Username:  ";
		UserName = ClsInputValidate::ReadString();
		while (!ClsUser::IsUserExist(UserName)) {
			cout << endl<<"User Not Found Enter Another One:  ";
			UserName = ClsInputValidate::ReadString();
		}
		ClsUser User = ClsUser::Find(UserName);
		_PrintUser(User);
		char Answer = 'n';
		cout << "\nAre You Sure You Want Update This User?(Y/N): ";
		cin >> Answer;
		if (toupper(Answer)=='Y')
		{
			cout << "\n\nUpdate User Info";
			cout << "\n------------------------\n";
			_ReadUserInfo(User);
			ClsUser::enSaveResuts Save;
			Save = User.Save();
			switch (Save)
			{
			case ClsUser::svFaildEmptyObject:
			{
				cout << "\nError User Wasn't Save Cause It's Empty\n";
				break;
			}
			case ClsUser::svSucceeded:
			{
				cout << "\nUser Updated Successfully" << endl;
				_PrintUser(User);
			}
				break;
			default:
				break;
			}

		}


	}

};

