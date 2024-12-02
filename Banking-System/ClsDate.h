#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<string>
#include "ClsString.h"

using namespace std;

class ClsDate
{
private:
    short _day = 1;
    short _month = 1;
    short _year = 1900;
    short _Hours ;
    short _Minutes;
    short _Second;

public:
    ClsDate() {
        //systemdate
        time_t t = time(0);
        tm* now = localtime(&t);
        _year = now->tm_year + 1900;
        _month = now->tm_mon + 1;
        _day = now->tm_mday;
 
    }
    ClsDate(short day, short month, short year) {
        _day = day;
        _month = month;
        _year = year;
    }
    ClsDate(string sDate) {
        vector<string>vDate;
        vDate = ClsString::split(sDate, "/");
        _day = stoi(vDate[0]);
        _month = stoi(vDate[1]);
        _year = stoi(vDate[2]);
    }
    ClsDate(short DayOrderInYear, short year) {


    }
    void setday(short day) {
        _day = day;
    }
    short getday() {
        return _day;
    }
    __declspec(property(get = getday, put = setday))short Day;
    void setmonth(short month) {
        _month = month;
    }
    short getmonth() {
        return _month;
    }
    __declspec(property(get = getmonth, put = setmonth))short Month;
    void setyear(short year) {
        _year = year;
    }
    short getyear() {
        return _year;
    }
    __declspec(property(get = getyear, put = setyear))short Year;
    void setHour(short Hour) {
        _Hours = Hour;
    }
    short getHour() {
        return _Hours;
    }
    __declspec(property(get = getHour, put = setHour))short Hour;
    void setMinutes(short Minutes) {
        _Minutes = Minutes;
    }
    short getMinutes() {
        return _Minutes;
    }
    __declspec(property(get = getMinutes, put = setMinutes))short Minutes;
    void setSecond(short Second) {
        _Second = Second;
    }
    short getSecond() {
        return _Second;
    }
    __declspec(property(get = getSecond, put = setSecond))short Second;
    static string DateToString(ClsDate date) {
        return to_string(date.Day) + "/" + to_string(date.Month) + "/" + to_string(date.Year);
    }
    static string GetSystemDateTimeString() {
        time_t t = time(0);
        tm* now = localtime(&t);
        short Year, Month, Day, Hour, Minute, Second;
        Year = now->tm_year + 1900;
        Month = now->tm_mon + 1;
        Day = now->tm_mday;
        Hour = now->tm_hour;
        Minute = now->tm_min;
        Second = now->tm_sec;
        return   to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " + to_string(Hour) + "-" + to_string(Minute) + "-" + to_string(Second);
    }
    string DateToString() {
        return DateToString(*this);
    }
    void print() {
        cout << DateToString() << endl;
    }
    static ClsDate Getsystemdate() {
        //systemdate
        time_t t = time(0);
        tm* now = localtime(&t);
        short day, month, year;
        year = now->tm_year + 1900;
        month = now->tm_mon + 1;
        day = now->tm_mday;
        return ClsDate(day, month, year);
    }
    static bool IsLeapYear(int year) {

        // if year is divisible by 4 AND not divisible by 100
        // OR if year is divisible by 400
        // then it is a leap ye
        return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

    }
    bool IsLeapYear() {
        return IsLeapYear(_year);
    }
    static short NumberOfDaysInMonth(short month, short year) {
        if (month < 1 || month>12)
            return 0;
        int NumberOfDays[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
        return(month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
    }
    short NumberOfDaysInMonth() {
        return NumberOfDaysInMonth(_month, _year);
    }
    static short DayOfWeekOrder(ClsDate date) {
        short a = (14 - date.Month) / 12;
        short y = date.Year - a;
        short m = date.Month + (12 * a) - 2;
        short d = (date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
        return d;
    }
    short DayOfWeekOrder() {
        return DayOfWeekOrder(*this);
    }
    static string dayName(short dayOrder) {
        string arrDays[]{ "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
        return arrDays[dayOrder];
    }
    string dayName() {
        short DayOrder = DayOfWeekOrder();
        return dayName(DayOrder);
    }
    static bool isWeekEnd(ClsDate date) {

        int day = DayOfWeekOrder(date);
        if (day == 5 || day == 6)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isWeekEnd() {
        return isWeekEnd(*this);
    }
    static bool IsBusinessDay(ClsDate date) {

        return !isWeekEnd(date);
    }
    bool IsBusinessDay() {
        return IsBusinessDay(*this);
    }
    static bool isLastDayInMonth(ClsDate date) {
        short numberOfDays = NumberOfDaysInMonth(date.Month, date.Year);
        return (date.Day == numberOfDays) ? true : false;
    }
    bool isLastDayInMonth() {
        return isLastDayInMonth(*this);
    }
    static bool isLastMonthInYear(short Month) {
        return (Month == 12) ? true : false;
    }
    bool isLastMonthInYear() {
        return isLastMonthInYear(_month);
    }
    static ClsDate AddOneDay(ClsDate date) {

        if (isLastDayInMonth(date))
        {
            if (isLastMonthInYear(date.Month))
            {
                date.Month = 1;
                date.Day = 1;
                date.Year++;
            }
            else
            {
                date.Month++;
                date.Day = 1;
            }
        }
        else
        {
            date.Day++;
        }
        return date;


    }
    void AddOneDay() {
        *this = AddOneDay(*this);
    }
    static ClsDate Add_X_Day(ClsDate date, short xDays) {
        for (int i = 1; i <= xDays; i++)
        {
            if (isLastDayInMonth(date))
            {
                if (isLastMonthInYear(date.Month))
                {
                    date.Month = 1;
                    date.Day = 1;
                    date.Year++;
                }
                else {
                    date.Month++;
                    date.Day = 1;
                }

            }
            else
            {
                date.Day++;
            }
        }
        return date;

    }
    void   Add_X_Day(short xDays) {
        *this = Add_X_Day(*this, xDays);
    }
    static  bool IsDate1BeforeDate2(ClsDate Date1, ClsDate Date2)
    {
        return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
    }
    bool IsDate1BeforeDate2(ClsDate Date2) {
        return IsDate1BeforeDate2(*this, Date2);
    }
    static bool IsDate1AfterDate2(ClsDate Date1, ClsDate Date2) {
        return !IsDate1BeforeDate2(Date1, Date2);
    }
    bool IsDate1AfterDate2(ClsDate Date2) {
        return IsDate1AfterDate2(*this, Date2);
    }

    static void swapDate(ClsDate& date1, ClsDate& date2) {
        ClsDate Temp;
        Temp = date1;
        date1 = date2;
        date2 = Temp;

    }
    static int calcDaysBetween2Dates(ClsDate Date1, ClsDate Date2) {
        int days = 0;
        while (IsDate1BeforeDate2(Date1, Date2))
        {
            days++;
            Date1 = AddOneDay(Date1);
        }
        return days;
    }
    static ClsDate IncreaseDateByOneWeek(ClsDate date) {
        short OneWeek = 7;
        for (int i = 1; i <= OneWeek; i++)
        {
            if (isLastDayInMonth(date))
            {
                if (isLastMonthInYear(date.Month))
                {
                    date.Month = 1;
                    date.Day = 1;
                    date.Year++;
                }
                else {
                    date.Month++;
                    date.Day = 1;
                }

            }
            else
            {
                date.Day++;
            }
        }
        return date;

    }
    void IncreaseDateByOneWeek() {
        *this = IncreaseDateByOneWeek(*this);
    }
    static ClsDate IncreaseDateBy_X_Week(ClsDate date, short xWeeks) {
        short OneWeek = 7;
        for (int i = 1; i <= OneWeek * xWeeks; i++)
        {
            if (isLastDayInMonth(date))
            {
                if (isLastMonthInYear(date.Month))
                {
                    date.Month = 1;
                    date.Day = 1;
                    date.Year++;
                }
                else {
                    date.Month++;
                    date.Day = 1;
                }

            }
            else
            {
                date.Day++;
            }
        }
        return date;

    }
    void IncreaseDateBy_X_Week(short xWeeks) {
        *this = IncreaseDateBy_X_Week(*this, xWeeks);
    }
    static ClsDate IncreaseDateByOneMonth(ClsDate date) {
        short month = 1;
        for (int i = 1; i <= month; i++)
        {
            if (isLastDayInMonth(date))
            {
                if (isLastMonthInYear(date.Month))
                {
                    date.Month = 1;
                    date.Day = 1;
                    date.Year++;
                }
                else {
                    date.Month++;
                    date.Day = 1;
                }

            }
            else
            {
                date.Month++;
            }
        }
        return date;

    }
    void IncreaseDateByOneMonth() {
        *this = IncreaseDateByOneMonth(*this);
    }
    static ClsDate IncreaseDateBy_X_Month(ClsDate date, short xMonth) {



        for (int i = 1; i <= xMonth; i++)
        {
            if (isLastDayInMonth(date))
            {
                if (isLastMonthInYear(date.Month))
                {
                    date.Month = 1;
                    date.Day = 1;
                    date.Year++;
                }
                else {
                    date.Month++;
                    date.Day = 1;
                }

            }
            else
            {
                date.Month++;
            }
        }
        return date;

    }
    void IncreaseDateBy_X_Month(short xMonth) {
        *this = IncreaseDateBy_X_Month(*this, xMonth);
    }
    static ClsDate IncreaseDateByOneYear(ClsDate date) {


        date.Year++;
        return date;

    }
    void IncreaseDateByOneYear() {
        *this = IncreaseDateByOneYear(*this);
    }
    static ClsDate IncreaseDateBy_X_Year(ClsDate date, short xYears) {
        date.Year += xYears;
        return date;
    }
    void IncreaseDateBy_X_Year(short xYears) {
        *this = IncreaseDateBy_X_Year(*this, xYears);
    }
    static short Age(ClsDate PerthDate) {
        short AgeByyear = 0;
        ClsDate Now;
        AgeByyear = Now.Year - PerthDate.Year;
        return AgeByyear;

    }
    static short NumberOfDayFromBegainingTheYear(ClsDate date) {
        int NumberOfDays[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (IsLeapYear(date.Year))
        {
            NumberOfDays[1] = 29;
        }
        else
        {
            NumberOfDays[1] = 28;
        }
        int daysFromBegainingTheYear = 0;
        for (int i = 0; i < date.Month - 1; i++)
        {
            daysFromBegainingTheYear += NumberOfDays[i];
        }
        daysFromBegainingTheYear += date.Day;
        return daysFromBegainingTheYear;
    }
    short NumberOfDayFromBegainingTheYear() {
        return  NumberOfDayFromBegainingTheYear(*this);
    }
    static short DaysUntillEndOfWeek(ClsDate date) {
        return 6 - DayOfWeekOrder(date);
    }
    short DaysUntillEndOfWeek() {
        return DaysUntillEndOfWeek(*this);
    }
    static short DaysUntillEndOfMonth(ClsDate date) {
        return NumberOfDaysInMonth(date.Month, date.Year) - date.Day;
    }
    short DaysUntillEndOfMonth() {
        return DaysUntillEndOfMonth(*this);
    }
    static short DaysUntillEndOfYear(ClsDate date) {
        return IsLeapYear(date.Year) ? 366 - NumberOfDayFromBegainingTheYear(date) : 365 - NumberOfDayFromBegainingTheYear(date);
    }
    short DaysUntillEndOfYear() {
        return DaysUntillEndOfYear(*this);
    }

    static	bool IsValidDate(ClsDate Date)
    {

        if (Date.Day < 1 || Date.Day>31)
            return false;

        if (Date.Month < 1 || Date.Month>12)
            return false;

        if (Date.Month == 2)
        {
            if (IsLeapYear(Date.Year))
            {
                if (Date.Day > 29)
                    return false;
            }
            else
            {
                if (Date.Day > 28)
                    return false;
            }
        }

        short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

        if (Date.Day > DaysInMonth)
            return false;

        return true;

    }

    bool IsValidDate()
    {
        return IsValidDate(*this);
    }


};

