#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsInputValidate.h"
#include "ClsDepositScreen.h"
#include "ClsWithdrawScreen.h"
#include "ClsTotalBalanceScreen.h"

using namespace std;
class ClsTransactionScreen:protected ClsScreen
{
private:
	enum enTransactionMenuOption{eDeposit=1,eWithdraw=2,eShowTotalBalance=3,eShowMainMenu=4};
	static short _ReadTransactionMenuOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do [1 to 4]: ";
		short Choice = ClsInputValidate::ReadIntNumberBetween(1, 4,"Invalid option ,enter option [1 to 4]: ");
		return Choice;
	}
	static void _GoBackToTransactionMenu() {
		cout << "Press eny Key to GoBack Transaction Menu.........";
		system("pause>0");
		ShowTransactionMenu();
	}

	static void _ShowDepositScreen() {
		ClsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithDrawScreen() {
		ClsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalanceScreen() {
		ClsTotalBalanceScreen::ShowTotalBalance();
	}
	static void _PerformTransactionMenuOption(enTransactionMenuOption Option) {
		switch (Option)
		{
		case ClsTransactionScreen::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case ClsTransactionScreen::eWithdraw:
		{
			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case ClsTransactionScreen::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case ClsTransactionScreen::eShowMainMenu:
		{
			//don't do any thing Main Menu will handle it
			break;
		}
		default:
			break;
		}
	}
public:
	static void ShowTransactionMenu() {
		system("cls");
		if (!ChickAccessRights(ClsUser::enPermission::pTransactions))
		{
			return;
		}
		_DrawScreenHeader("\t  Transaction Scerrn");
			cout << setw(37) << left << "" << "===================================\n";
			cout << setw(37) << left << "" << "\t\t  Transaction Menu \n";
			cout << setw(37) << left << "" << "===================================\n";
			cout << setw(37) << left << "" << "\t[1] Deposit\n";
			cout << setw(37) << left << "" << "\t[2] Withdraw\n";
			cout << setw(37) << left << "" << "\t[3] Total Balance\n";
			cout << setw(37) << left << "" << "\t[4] Main Menu\n";
			cout << setw(37) << left << "" << "===================================\n";
			_PerformTransactionMenuOption(enTransactionMenuOption(_ReadTransactionMenuOption()));
	}
};

