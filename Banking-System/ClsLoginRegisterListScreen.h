#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "ClsString.h"
#include "ClsUser.h"
#include "ClsScreen.h"
using namespace std;
class ClsLoginRegisterListScreen:protected ClsScreen
{
	static void PrintClientsResult(ClsUser::StLoginRegister User) {
		cout << setw(8) << left << "" << "| " << left << setw(35)<< User.Date;
		cout << "| " << left << setw(20) << User.UserName;
		cout << "| " << left << setw(20) << User.Password;
		cout << "| " << left << setw(10) << User.permission;



	}
public:
	static void ShowLoginRegisterList() {
		if (!ChickAccessRights(ClsUser::enPermission::pLoginRegistrationList))
		{
			return;
		}
		vector <ClsUser::StLoginRegister>LoginRegister;
		LoginRegister = ClsUser::GetLoginRegisterList();
		string Title = "\t  Login Register List Screen";
		string SubTitle = "\t    (" + to_string(LoginRegister.size()) + ") User(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "permission";


		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;
		if (LoginRegister.size() == 0)
			cout << "\t\t\t\tNo Login Register Available in the system!" << endl;
		else
			for (ClsUser::StLoginRegister& R : LoginRegister) {
				PrintClientsResult(R);
				cout << endl;
			}
		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;

	}
};

