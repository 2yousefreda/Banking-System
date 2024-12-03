#pragma once
#include <iostream>
#include <iomanip>
#include "ClsInputValidate.h"
#include "ClsScreen.h"
#include "ClsUser.h"
#include "Global.h"
using namespace std;
class ClsDeleteUserScreen:protected ClsScreen
{

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
	static void ShowDeleteUserScreen() {

		string Title = "\t  Delete User Screen";
		_DrawScreenHeader(Title);
		string UserName = "";
		cout << "\nEnter UserName:   ";
		UserName = ClsInputValidate::ReadString();
	
			while (!ClsUser::IsUserExist(UserName))
			{
			
					cout << "\nError User Not Exist Enter Another One: ";

					UserName = ClsInputValidate::ReadString();

				
			}
		ClsUser User = ClsUser::Find(UserName);
		_PrintUser(User);
		cout << "\n\nAre you sure for delete this User(Y/N) ";
		char Answer = 'n';
		cin >> Answer;
		if (toupper(Answer)=='Y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully!\n";
				_PrintUser(User);

			}
			else
			{
				cout << "\nUser wasn't Deleted \n";
			}
		}
	}
};

