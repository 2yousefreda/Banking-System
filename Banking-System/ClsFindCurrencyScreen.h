#pragma once
#include <iostream>
#include "ClsScreen.h"
#include "ClsCurrency.h"
#include "ClsString.h"
#include "ClsInputValidate.h"
using namespace std;
class ClsFindCurrencyScreen :
    protected ClsScreen
{
    static void _PrintCurrency(ClsCurrency Currency) {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency is found";
        cout << "\n\nCurrency Card:\n";
        cout << "_______________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_______________________________\n";
        }
        else
        {
            cout << "currency Not Found!";
        }

    }
public:
    static void FindCurrencyScreen() {
        string Title = "\t Find Currency Screen";
        _DrawScreenHeader(Title);
        short Num = 1;
        cout << "\nFind Currency BY : [1]Code or [2]Country? : ";
        Num = ClsInputValidate::ReadIntNumberBetween(1, 2,"Invalid Option, Enter Again: ");
        if (Num==1)
        {
            string CurrencyCode;
            cout << "\nEnter Currency Code: ";
            cin >> CurrencyCode;
            ClsCurrency  Currency = ClsCurrency::FindByCode(CurrencyCode);
            _PrintCurrency(Currency);
        }
        else
        {
            string Country;
            cout << "\nEnter Currency Code: ";
            cin >> Country;
            ClsCurrency  Currency = ClsCurrency::FindByCountry(Country);
            _PrintCurrency(Currency);
        }
      
    }
};

