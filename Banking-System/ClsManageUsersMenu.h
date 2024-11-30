#pragma once
#include <iostream>
#include <iomanip>
#include "ClsInputValidate.h"
#include "ClsScreen.h"
#include "ClsListUsersScreen.h"
#include "ClsAddNewUserScreen.h"
#include "ClsDeleteUserScreen.h"
#include "ClsFindUserScreen.h"
using namespace std;
class ClsManageUsersMenu :protected ClsScreen
{
private:
	enum enManageUsersMenuOption { eShowListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenu = 6 };
	static void _GoBackManageUsersMenu() {
		cout << "Press any Key to Go Back to Manage Users Menu.........";
		system("pause>0");
		ShowManageUsersMenu();
	}
	static short _readManageUsersOption() {
		cout << setw(37) << left << "" << "Chose What do you want to do? [1 to 6]: ";
		short Option = ClsInputValidate::ReadIntNumberBetween(1, 6, "invalid Option, enter another one\n");
		return Option;
	}
	static void _ShowListUsers() {
		//cout << "Hear will be ListUsers screen";
		ClsListUsersScreen::ShowClientsList();
	}
	static void _ShowAddNewUser() {
		//cout << "Hear will be AddNewUser screen";
		ClsAddNewUserScreen::ShowAddNewUser();
	}
	static void _ShowDeleteUser() {
		//cout << "Hear will be DeleteUser screen";
		ClsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUser() {
		cout << "Hear will be UpdateUser screen";
	}
	static void _ShowFindUsers() {
		//cout << "Hear will be FindUsers screen";
		ClsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenuOption(enManageUsersMenuOption Option) {
		switch (Option)
		{
		case ClsManageUsersMenu::eShowListUsers:
		{
			system("cls");
			_ShowListUsers();
			_GoBackManageUsersMenu();
			break;
		}
		case ClsManageUsersMenu::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUser();
			_GoBackManageUsersMenu();
			break;
		}
		case ClsManageUsersMenu::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUser();
			_GoBackManageUsersMenu();
			break;
		}
		case ClsManageUsersMenu::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUser();
			_GoBackManageUsersMenu();
			break;
		}
		case ClsManageUsersMenu::eFindUser:
		{
			system("cls");
			_ShowFindUsers();
			_GoBackManageUsersMenu();
			break;
		}
		case ClsManageUsersMenu::eMainMenu:
		{
			

			break;
		}
		default:
			break;
		}
	}
public:
	static void ShowManageUsersMenu() {
		system("cls");
		_DrawScreenHeader("\tManage Users Screen");
		cout << setw(37) << left << "" << "============================\n";
		cout << setw(37) << left << "" << "\t   Manage Users Menu\n";
		cout << setw(37) << left << "" << "============================\n";
		cout << setw(37) << left << "" << "\t[1] Show Users List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "============================\n";
		_PerformManageUsersMenuOption(enManageUsersMenuOption(_readManageUsersOption()));
	}
};

