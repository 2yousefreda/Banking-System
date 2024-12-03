#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h"
#include "ClsCurrency.h"
using namespace std;
class ClsCurrencyListScreen:protected ClsScreen
{
	static void _PrintCurrenciesData(ClsCurrency Currency) {
		cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(10) << Currency.CurrencyCode();
		cout << "| " << left << setw(40) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();
	}
public:
	static void CurrencyListScreen() {
		vector <ClsCurrency>vCurrencies;
		vCurrencies = ClsCurrency::GetCurrenciesList();
		string Title = "\t  Currencies List Screen ";
		string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") User(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(10) << "Rate";


		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;
		if (vCurrencies.size() == 0)
			cout << "\t\t\t\tNo Login Register Available in the system!" << endl;
		else
			for (ClsCurrency& C : vCurrencies) {
				_PrintCurrenciesData(C);
				cout << endl;
			}
		cout << "\n\t________________________________________________";
		cout << "__________________________________________________\n" << endl;
	}
};

