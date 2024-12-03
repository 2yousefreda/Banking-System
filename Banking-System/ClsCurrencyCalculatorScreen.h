#pragma once
#include "ClsScreen.h"
#include "ClsCurrency.h"
#include "ClsInputValidate.h"
using namespace std;
class ClsCurrencyCalculatorScreen :
    protected ClsScreen
{
    static void _PrintCurrencyCard(ClsCurrency Currency,string Message) {
        
            cout << "\n\nConvert "<<Message<<": \n";
            cout << "_______________________________\n";
            cout << "\nCountry    : " << Currency.Country();
            cout << "\nCode       : " << Currency.CurrencyCode();
            cout << "\nName       : " << Currency.CurrencyName();
            cout << "\nRate(1$) = : " << Currency.Rate();
            cout << "\n_______________________________\n";

    }
    static float _ReadAmount() {
        cout << "\nEnter Amount to Exchange: ";
        float Amount=ClsInputValidate::ReadDoubleNumber();
        return Amount;

    }
    static ClsCurrency _GetCurrency(string Message) {
        string CurrencyCode;
        cout << Message;
        CurrencyCode = ClsInputValidate::ReadString();
        while (!ClsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Not Found Enter Another One:  ";
            CurrencyCode = ClsInputValidate::ReadString();
        }
        ClsCurrency Currency1 = ClsCurrency::FindByCode(CurrencyCode);
        return Currency1;
    }
    static void ExchangeCurrencies(float Amount, ClsCurrency CurrencyForm, ClsCurrency CurrencyTo) {
        _PrintCurrencyCard(CurrencyForm, "From");
        float AmountInUSD = CurrencyForm.ConvertToUSD(Amount);
        cout << Amount << " " << CurrencyForm.CurrencyCode() << " = " << AmountInUSD << " USD\n\n";
        if (CurrencyTo.CurrencyCode()=="USD")
        {
            return;
        }
        cout << "\nConverting from USD to:\n";
        _PrintCurrencyCard(CurrencyTo, "To");
        float AmountInCurrencyTo = CurrencyForm.ConvertToOutherCurrency(Amount, CurrencyTo);

    cout << Amount << " " << CurrencyForm.CurrencyCode() << " = " << AmountInCurrencyTo << " " << CurrencyTo.CurrencyCode();
    }
public:
    static void CurrencyCalulatorScreen() {
      
        string Title = "\t Currency Calulator Screen";
                char Answer = 'n';
        do
        {
            system("cls");
        _DrawScreenHeader(Title);
        ClsCurrency CurrencyForm = _GetCurrency("\nEnter Currency Code that you whant to Exchange From: ");
        ClsCurrency Currencyto = _GetCurrency("\nEnter Currency Code that you whant to Exchange To: ");
        float Amount = _ReadAmount();
        ExchangeCurrencies(Amount, CurrencyForm, Currencyto);
        cout << "\nDo you want to Exchange Anothe Currency (Y/N): ";
        cin >> Answer;
                
        } while (toupper(Answer)=='Y');
        
     

    }


};

