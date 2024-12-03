#pragma once
#include "ClsScreen.h"
#include "ClsCurrency.h"
#include "ClsInputValidate.h"
using namespace std;
class ClsUpdateCurrencyRateScreen :
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
    static float _ReadRate() {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;
        NewRate = ClsInputValidate::ReadDoubleNumber();
        return NewRate;
    }
public:
    static void UpdateCurrencyScreen() {
        string Title = "\t Update Curreny Screen";
        _DrawScreenHeader(Title);
       
            string CurrencyCode;
            cout << "\nEnter Currency Code: ";
            CurrencyCode=ClsInputValidate::ReadString();
            while (!ClsCurrency::IsCurrencyExist(CurrencyCode))
            {
            cout << "\nCurrency Not found Enter Another one : ";
            CurrencyCode=ClsInputValidate::ReadString();
            

            }
            ClsCurrency  Currency = ClsCurrency::FindByCode(CurrencyCode);
            _PrintCurrency(Currency);
            cout << "\nAre you sure you want to update rate of this currency(Y/N): ";
                char answer = 'n';
                cin >> answer;
                if (toupper(answer)=='Y')
                {
                    cout << "\n\nUpdate Currency Rate: ";
                    cout << "\n---------------------------\n";
                    Currency.UpdateRate(_ReadRate());
                    cout << "\nCurrency Rate Updated Successfully :-)\n";
                    _PrintCurrency(Currency);
                        
                }
      

    }
};

