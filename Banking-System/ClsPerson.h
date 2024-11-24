#pragma once
#include <iostream>
#include <string>
using namespace std;

class ClsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Phone;
	string _Email;
public:
	ClsPerson(string FirstName, string LastName,string Phone, string Email){
		_FirstName = FirstName;
		_LastName = LastName;
		_Phone = Phone;
		_Email = Email;
	}

	void SetFirstName(string FirstName) {
		_FirstName = FirstName;
	}
	string GetFirstName() {
		return _FirstName;
	}
	__declspec(property(put = SetFirstName, get = GetFirstName)) string FirstName;

		void SetLastName(string LastName) {
		_LastName = LastName;
	}
	string GetLastName() {
		return _LastName;
	}
	__declspec(property(put = SetLastName, get = GetLastName)) string LastName;


	void SetPhone(string Phone) {
		_Phone = Phone;
	}
	string GetPhone() {
		return _Phone;
	}
	__declspec(property(put = SetPhone, get = GetPhone)) string Phone;

	void SetEmail(string Email) {
		_Email = Email;
	}
	string GetEmail() {
		return _Email;
	}
	__declspec(property(put = SetEmail, get = GetEmail)) string Email;

	string FullName() {
		return _FirstName + " " + _LastName;
	}

	

};

