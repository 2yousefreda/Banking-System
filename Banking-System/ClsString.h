#pragma once
#include<iostream>
#include<vector>
using namespace std;
class ClsString
{
private:
	string _Value;
protected:
	static bool chickifvowel(char x) {
		x = tolower(x);
		return (x == 'a' || x == 'o' || x == 'i' || x == 'e' || x == 'u');
	}
public:
	ClsString(string value) {
		_Value = value;
	}
	ClsString() {
		_Value = "";
	}
	//property set
	void SetValue(string value) {
		_Value = value;
	}
	//property Get
	string GetValue() {
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue))string Value;

	// start count words
	static int CountWords(string s1) {
		int counter = 0;
		string delim = " ";

		short pos = 0;
		string word;
		while ((pos = s1.find(delim)) != std::string::npos)
		{
			word = s1.substr(0, pos);//store the word
			if (word != "")
			{
				counter++;
			}
			s1.erase(0, pos + delim.length()); //erese() until position and move to next word.
		}

		if (s1 != "")
		{
			counter++;
		}
		return counter;
	}
	int CountWords() {
		return CountWords(_Value);
	}
	// end count words

	//start trem
	static string  trimLeft(string s1) {
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ')
			{
				return s1.substr(i, s1.length() - 1);
			}
		}
		return "";
	}
	static string  trimreigt(string s1) {

		for (int i = s1.length() - 1; i >= 0; i--)
		{
			if (s1[i] != ' ')
			{
				return s1.substr(0, i + 1);
			}
		}
		return "";
	}
	static string  trim(string s1) {
		return trimLeft(trimreigt(s1));
	}

	string  trimLeft() {
		return trimLeft(_Value);
	}
	string  trimreigt() {
		return trimreigt(_Value);
	}
	string  trim() {
		return trim(_Value);
	}
	//end trem

	//start join string 
	static string joinstring(vector <string> vstring, string delim) {
		string words = "";
		for (string& x : vstring) {
			words += x + delim;
		}
		return words.substr(0, words.length() - delim.length());
	}
	static string joinstring(string arr[], int arrLength, string delim) {
		string words = "";
		for (int i = 0; i < arrLength; i++)
		{
			words += (arr[i] + delim);
		}
		return words.substr(0, words.length() - delim.length());


	}
	//end join string 

	//start split string
	static vector <string>split(string s1, string delim) {

		vector <string> vstring;
		short pos;
		string word;
		//use find() function to get the position of the edlimiters;
		while ((pos = s1.find(delim)) != std::string::npos)
		{
			word = s1.substr(0, pos);//store the word
			if (word != "")
			{
				vstring.push_back(word);
			}
			s1.erase(0, pos + delim.length());
		}
		if (s1 != "")
		{
			vstring.push_back(s1);
		}
		return vstring;
	}
	vector <string>split(string delim) {
		return split(_Value, delim);
	}
	//end split

	//start reverse
	static string reverse(string s1) {
		vector <string>vstring;
		string s2 = "";
		vstring = split(s1, " ");
		vector <string>::iterator itr = vstring.end();
		while (itr != vstring.begin())
		{
			--itr;
			s2 += *itr + " ";
		}
		s2 = trimreigt(s2);
		return s2;
	}
	string reverse() {
		return reverse(_Value);
	}
	//end reverse

	//start reblace
	static string reblaceWord(vector <string>vstring, string Oldword, string NewWord) {
		string word = "";
		for (string& x : vstring) {
			if (x != Oldword)
			{
				word += (x + " ");
			}
			else
			{
				word += (NewWord + " ");
			}

		}

		return word;
	}
	static string reblaceWord(string s1, string Oldword, string NewWord) {
		short pos = s1.find(Oldword);
		while (pos != std::string::npos)
		{
			s1 = s1.replace(pos, Oldword.length(), NewWord);
			pos = s1.find(Oldword);
		}
		return s1;
	}
	string reblaceWord(string Oldword, string NewWord) {
		return reblaceWord(_Value, Oldword, NewWord);
	}
	//end reblace

	//start remove punct
	static string RemovePunct(string s1) {
		string s2 = "";
		for (int i = 0; i < s1.length(); i++)
		{
			if (!ispunct(s1[i]))
			{
				s2 += s1[i];
			}
		}
		return s2;
	}
	string RemovePunct() {
		return RemovePunct(_Value);
	}
	//end remove Punct

	//start Char Counter
	static int CharCounter(string word, char x, bool machcase = true) {
		int counter = 0;
		for (int i = 0; i < word.length(); i++)
		{
			if (machcase)
			{
				if (word[i] == x)
				{
					counter++;
				}

			}
			else
			{
				if (tolower(word[i]) == tolower(x))
				{
					counter++;
				}
			}
		}


		return counter;
	}
	int CharCounter(char x, bool machcase = true) {
		return CharCounter(_Value, x, machcase);
	}
	//end Char Counter

	//start invert
	static string invert(string word) {


		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] >= 65 && word[i] <= 122)
			{
				if (word[i] >= 97 && word[i] <= 122)
				{
					word[i] = toupper(word[i]);

				}
				else
				{
					word[i] = tolower(word[i]);

				}
			}




		}
		return word;
	}
	string invert() {
		return invert(_Value);
	}
	//End invert

	//start Cabetal First Letter
	static string capitalfirstL(string word) {
		bool isfirstL = true;

		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] != ' ' && isfirstL)
			{
				word[i] = toupper(word[i]);

			}


			isfirstL = (word[i] == ' ' ? true : false);

		}
		return word;
	}
	string capitalfirstL() {
		return capitalfirstL(_Value);
	}
	//end Cabetal First Letter

	//start vowel
	static int vowelcounter(string words) {
		int counter = 0;
		for (int i = 0; i < words.length(); i++)
		{
			if (chickifvowel(words[i]))
			{
				counter++;
			}
		}
		return counter;
	}
	int vowelcounter() {
		return vowelcounter(_Value);
	}
	//end vowel

	//start Get first char
	static string getfirstchar(string word) {
		bool isfirstL = true;
		string x = "";
		string delim = " , ";
		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] != ' ' && isfirstL)
			{
				x += word[i];
				x += " , ";
			}
			isfirstL = (word[i] == ' ' ? true : false);
		}

		return x.substr(0, x.length() - delim.length());
	}
	string getfirstchar() {
		return getfirstchar(_Value);
	}
	//end Get first char


	//start toUpper
	static string ToUpper(string word) {


		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] != ' ')
			{
				word[i] = toupper(word[i]);

			}
		}
		return word;
	}
	string ToUpper() {
		return ToUpper(_Value);
	}
	//end toUpper

	//statr to lower
	static string ToLower(string word) {


		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] != ' ')
			{
				word[i] = tolower(word[i]);

			}




		}
		return word;
	}
	string ToLower() {
		return ToLower(_Value);
	}
	//end to lower

	//start length
	static int Length(string word) {
		int counter = 0;

		for (int i = 0; i < word.length(); i++)
		{
			counter++;
		}
		return counter;
	}
	int Length() {
		return Length(_Value);
	}

};

