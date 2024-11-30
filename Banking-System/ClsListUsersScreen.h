#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsUser.h"

#include <vector>
using namespace std;
class ClsListUsersScreen:protected ClsScreen
{
	static void PrintClientsResult(ClsUser User) {
		cout << setw(8) << left<<"" << "| " <<left  << setw(12) << User.UserName;
		cout << "| " << setw(25) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permission;


	}
public:
	static void ShowClientsList() {

		vector <ClsUser>vUsers;
		vUsers = ClsUser::GetUsersList();
		string Title = "\t  User List Screen";
		string SubTitle = "\t    (" + to_string(vUsers.size()) + ") client(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
		cout << "| " << setw(25) << left << "Full Name";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(20) << left << "Email";
		cout << "| " << setw(10) << left << "Password";
		cout << "| " << setw(12) << left << "Permission";

		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;
		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo CLient Available in the system!" << endl;
		else
			for (ClsUser& C : vUsers) {
				PrintClientsResult(C);
				cout << endl;
			}
		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;

	}
};

