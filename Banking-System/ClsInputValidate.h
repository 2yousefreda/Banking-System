#pragma once
#include "ClsString.h"
#include "ClsDate.h"
#include "ClsUtility.h"
#include <iostream>
using namespace std;


class ClsInputValidate
{
public:
	static bool IsNumberBetween(int input,int start ,int end) {
		if (input>=start&&input<=end)
		{
			return true;
		}
		else
		{
			return false;
		}
	}	
	static bool IsNumberBetween(double input,double start ,double end) {
		if (input>=start&&input<=end)
		{
			return true;
		}
		else
		{
			return false;
		}
	}	
	static bool IsNumberBetween(short input,short start ,short end) {
		if (input>=start&&input<=end)
		{
			return true;
		}
		else
		{
			return false;
		}
	}	
	static bool IsNumberBetween(float input,float start ,float end) {
		if (input>=start&&input<=end)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static bool IsDateBetween(ClsDate date,ClsDate dateFrom,ClsDate dateTo) {
		if (ClsDate::IsDate1AfterDate2(dateFrom, dateTo))
		{
			ClsUtility::Swap(dateFrom, dateTo);
		}
		if (ClsDate::IsDate1AfterDate2(date, dateFrom)&&ClsDate::IsDate1BeforeDate2(date, dateTo))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	static int ReadIntNumber(string WrongMessage="Invalid Number ,Enter again\n") {
		int Number;
		
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << WrongMessage;
			
		}
			
		return Number;
	}	
	static string ReadString(string WrongMessage="Invalid string ,Enter again\n") {
		string word;
		
		while (!(cin >> word))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << WrongMessage;
			
		}
			
		return word;
	}
	static int ReadIntNumberBetween(int from,int to,string WrongMessage="Invalid Number ,Enter again") {
		int Number =ReadIntNumber();
		
		while (!IsNumberBetween(Number,from,to))
		{
	
			cout << WrongMessage<<endl;
			Number = ReadIntNumber();
		}
		return Number;
	}
	static double ReadDoubleNumber(string WrongMessage = "Invalid Number ,Enter again\n") {
		double Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << WrongMessage;

		}

		return Number;
	}
	static double ReadDoubleNumberBetween(double from, double to, string WrongMessage = "Invalid Number ,Enter again\n") {
		double Number = ReadDoubleNumber();

		while (!(IsNumberBetween(Number, from, to)))
		{

			cout << WrongMessage;
			Number = ReadDoubleNumber();
		}
		return Number;
	}
	static bool IsValideDate(ClsDate date) {
		return ClsDate::IsValidDate(date);
	}
};

