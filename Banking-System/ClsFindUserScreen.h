#pragma once
#include <iostream>
#include <iomanip>
#include "ClsUser.h"
#include "ClsInputValidate.h"
#include "ClsScreen.h"
using namespace std;
class ClsFindUserScreen:protected ClsScreen
{
	static void _PrintUser(ClsUser User) {
		cout << "\nUser Card:";
		cout << "\n-------------------------";
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
	static void ShowFindUserScreen() {
		string Title = "\t   Find User Screen";
		_DrawScreenHeader(Title);
		string UserName = "";
		cout << "\nEnter User Name: ";
		UserName = ClsInputValidate::ReadString();
		while (!ClsUser::IsUserExist(UserName)) {
			cout << "\nUser Not Exist Enter Another one: ";
			UserName = ClsInputValidate::ReadString();
		}
			ClsUser User = ClsUser::Find(UserName);
		if (!User.IsEmpty())
		{
			cout << "\nUser Found!\n";
			_PrintUser(User);
		}
		else
		{
			cout << "\nUser not Found!\n";
		}

	}
};

