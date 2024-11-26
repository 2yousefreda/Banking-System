#pragma once
#include <iostream>
#include <iomanip>

#include "ClsScreen.h"
#include "ClsInputValidate.h"

#include "ClsClientListScreen.h"
#include  "ClsAddNewClientScreen.h"	
#include  "ClsDeleteClientScreen.h"	
#include  "ClsUpdateClientScreen.h"	
#include  "ClsFindClientScreen.h"	
#include  "ClsTransactionScreen.h"	



using namespace std;
class ClsMainScreen : protected ClsScreen
{
private:
	enum enMainMenuOption { eShowClient = 1, eAddNewClient = 2, eDaleteClient = 3, eUpdateClient = 4, eFindClient = 5, eTransaction = 6, eManageUsers = 7, eLogout = 8 };
	
	static short _ReadMainMenuOption() {
		cout << setw(37) << left << "" << "Chose What do you want to do? [1 to 8]";
		short Choice = ClsInputValidate::ReadIntNumberBetween(1, 8);
		return Choice;
	}
	static void _GoBackToMainMenu() {
		cout << "\n\tpress eny Key to GoBack.....";
		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowAllClientScreen() {
		ClsClientListScreen::ShowClientsList();
	}	
	static void _ShowAddNewClienttScreen() {
		ClsAddNewClientScreen::AddNewClient();
	}
	static void _ShowDeleteClientScreen() {
		ClsDeleteClientScreen::DalateClinet();
	}
	static void _ShowUpdateClientScreen() {
		ClsUpdateClientScreen::UpdateClient();
	}
	static void _ShowFindClientScreen() {
		ClsFindClientScreen::FindClientScreen();
	}	
	static void _ShowTransactionScreen() {
		ClsTransactionScreen::ShowTransactionMenu();
	}
	static void _ShowManageUsersScreen() {
		cout << "hear will be ManageUsersScreen \n";
	}
	static void _ShowLogoutScreen() {
		cout << "lofgsd";
	}
	static void _PerformMainMenuOption(enMainMenuOption MainMenuOption){
		switch (MainMenuOption)
		{
		case ClsMainScreen::eShowClient:
		{
			system("cls");
			_ShowAllClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case ClsMainScreen::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClienttScreen();
			_GoBackToMainMenu();
			break;
		}
		case ClsMainScreen::eDaleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case ClsMainScreen::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case ClsMainScreen::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case ClsMainScreen::eTransaction:
		{
			system("cls");
			_ShowTransactionScreen();
			_GoBackToMainMenu();
			break;
		}
		case ClsMainScreen::eManageUsers:
		{
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;
		}
		case ClsMainScreen::eLogout:
		{
			system("cls");
			_ShowLogoutScreen();
			_GoBackToMainMenu();
			break;
		}
		default:
			break;
		}
	}
public:
	static void ShowMainMenu() {
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left << "" << "============================\n";
		cout << setw(37) << left << "" << "\t\tMain Menu\n";
		cout << setw(37) << left << "" << "============================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Logout.\n";
		_PerformMainMenuOption(enMainMenuOption(_ReadMainMenuOption()));
	}

};

