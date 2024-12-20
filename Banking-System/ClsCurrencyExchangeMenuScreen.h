#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsCurrency.h"
#include "ClsUser.h"
#include "ClsInputValidate.h"
#include "ClsCurrencyListScreen.h"
#include "ClsFindCurrencyScreen.h"
#include "ClsUpdateCurrencyRateScreen.h"
#include "ClsCurrencyCalculatorScreen.h"
using namespace std;
class ClsCurrencyExchangeMenuScreen :protected ClsScreen
{

	enum enCurrencyExchangeMenuOption {eCurrenciesList=1,eFindCurrency=2,eUpdateCurrency=3,CurrencyCalculator=4,eMainMenu=5 };
	static int _ReadMenuOption() {
		short Option;
		cout << "\nChoose what do you want to do? [1 to 5]:  ";
		Option = ClsInputValidate::ReadIntNumberBetween(1, 5,"Invalid Opration ,Enter again");
		return Option;
	}
	static void _GoBackToCurrencyExchangeMenu() {
		cout << "\n\tpress eny Key to GoBack.....";
		system("pause>0");
		CurrencyExchangeMenuScreen();
	}
	static void _ShowCurrenciesListScreen() {
		//cout << "ListCurrenciesScreen will be hear\n";
		ClsCurrencyListScreen::CurrencyListScreen();
	}
	static void _ShowFindCurrencyScreen() {
		ClsFindCurrencyScreen::FindCurrencyScreen();
	}
	static void _ShowUpdateCurrencyScreen() {
		ClsUpdateCurrencyRateScreen::UpdateCurrencyScreen();
	}
	static void _ShowCurrencyCalculatorScreen() {
		ClsCurrencyCalculatorScreen::CurrencyCalulatorScreen();
	}

	static void _PerformCurrencyExchangeMenu(enCurrencyExchangeMenuOption Option) {
		switch (Option)
		{
		case ClsCurrencyExchangeMenuScreen::eCurrenciesList:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case ClsCurrencyExchangeMenuScreen::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case ClsCurrencyExchangeMenuScreen::eUpdateCurrency:
		{
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case ClsCurrencyExchangeMenuScreen::CurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case ClsCurrencyExchangeMenuScreen::eMainMenu:

			break;
		default:
			break;
		}
	}
public:
	static void CurrencyExchangeMenuScreen() {
		if (!ChickAccessRights(ClsUser::enPermission::pCurrencyExchange))
		{
			return;
		}
		system("cls");
		string Title = "   Currency Exchange MenuS creen";
			_DrawScreenHeader(Title);
			cout << setw(32) << left << "" << "========================================\n";
			cout << setw(32) << left << "" << "         Currency Exchange Menu       \n";
			cout << setw(32) << left << "" << "========================================\n";
			cout << setw(37) << left << "" << "\t[1] Currencies List.\n";
			cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
			cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
			cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
			cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
			_PerformCurrencyExchangeMenu(enCurrencyExchangeMenuOption(_ReadMenuOption()));
	}

};

