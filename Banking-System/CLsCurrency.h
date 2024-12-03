#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "ClsString.h";
using namespace std;
class ClsCurrency
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	static ClsCurrency _GetEmptyCurrencyObject() {
		return ClsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
	static ClsCurrency _ConvertDataLineToCurrenyOpject(string Line,string separator="#//#") {
		vector <string>vCurrency;
		vCurrency = ClsString::split(Line, separator);
		return ClsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3]));
	}
	static string _ConverCurrencyObjectToLine(ClsCurrency Currency, string Seperator = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency.CurrencyCode() + Seperator;
		stCurrencyRecord += Currency.CurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;

	}
	static void _SaveCurrencyDataToFile(vector <ClsCurrency> vCurrencys)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (ClsCurrency C : vCurrencys)
			{
				DataLine = _ConverCurrencyObjectToLine(C);
				MyFile << DataLine << endl;
			}

			MyFile.close();

		}

	}
	static vector<ClsCurrency>_LoadDataFromFile() {
		vector<ClsCurrency>vCurrencys;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
			if (MyFile.is_open())
			{
				string Line;
				while (getline(MyFile,Line))
				{
					ClsCurrency Currency = _ConvertDataLineToCurrenyOpject(Line);
					vCurrencys.push_back(Currency);
				}
				MyFile.close();
			}
				return vCurrencys;
			
	}
	void _Update() {
		vector <ClsCurrency>_vCurrency;
		_vCurrency = _LoadDataFromFile();
		for (ClsCurrency &C:_vCurrency) {
			if (C.CurrencyCode()==CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(_vCurrency);
	}
public:
	ClsCurrency(enMode Mode,string Country,string CurrencyCode,string CurrencyName,float Rate) 
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string Country() {
		return _Country;
	}
	string CurrencyCode() {
		return _CurrencyCode;
	}
	string CurrencyName() {
		return _CurrencyName;
	}
	void UpdateRate() {

	}
	float Rate() {
		return _Rate;
	}
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}
	static   ClsCurrency FindByCode(string CurrencyCode)
	{

		CurrencyCode = ClsString::ToUpper(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				ClsCurrency Currency = _ConvertDataLineToCurrenyOpject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}
	static   ClsCurrency FindByCountry(string Country)
	{
		Country = ClsString::ToUpper(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				ClsCurrency Currency = _ConvertDataLineToCurrenyOpject(Line);
				if (ClsString::ToUpper(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		ClsCurrency C1 = ClsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());

	}

	static vector <ClsCurrency> GetCurrenciesList()
	{
		return _LoadDataFromFile();
	}

};

