#pragma once
#include<iostream>
#include<string>
#include<cstdlib>

#include "ClsString.h"
#include "ClsDate.h"
using namespace std;
class ClsUtility
{
public:
    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void Srand() {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int from, int to) {
        int randnum = rand() % (to - from + 1) + from;
        return randnum;
    }
    static  char GetRandomCharacter(enCharType CharType) {

        if (CharType == MixChars)
        {
            CharType = (enCharType)RandomNumber(1, 3);
        }
        switch (CharType)
        {
        case SamallLetter:
            return char(RandomNumber(97, 122));
            break;
        case CapitalLetter:
            return char(RandomNumber(65, 90));
            break;
        case SpecialCharacter:
            return char(RandomNumber(33, 47));
            break;
        case Digit:
            return char(RandomNumber(48, 57));
            break;
        }

    }
    static string Encryption(string text, int incriptionKey) {
        for (int i = 0; i < text.length(); i++)
        {
            text[i] = char((int)text[i] + incriptionKey);
        }
        return text;
    }
    static string Decryption(string text, int incriptionKey) {
        for (int i = 0; i < text.length(); i++)
        {
            text[i] = char((int)text[i] - incriptionKey);
        }
        return text;
    }
    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word;

        for (int i = 1; i <= Length; i++)

        {

            Word = Word + GetRandomCharacter(CharType);

        }
        return Word;
    }
    static string GenerateKey(enCharType chatType = CapitalLetter) {
        string key = "";
        int counter = 0;
        for (int i = 0; i <= 4; i++)
        {

            //GetRandomCharacter(ClsUtil::MixChars);
            key += GenerateWord(chatType, 4);
            key += "-";

        }
        if (!key.empty()) {
            key.pop_back();
        }
        return key;

    }
    static void GenerateKeys(int NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }

    }
    static void FillArrayWith1toN(int arr[100], int arrLength, int from, int to)
    {
        for (int i = 0; i < arrLength; i++) {

            arr[i] = RandomNumber(from, to);
        }
    }
    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);

    }
    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }
    static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }
    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }
    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }
    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }
    static  void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }
    static  void Swap(ClsDate& A, ClsDate& B)
    {
        ClsDate::swapDate(A, B);

    }
    static  void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }
    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

};

