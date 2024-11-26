#pragma once
#include <iostream>
#include <string>
using namespace std;
class EncryptionKey
{



public:
	EncryptionKey() {
	}
	static int _EncryptionKey;
	static int GetEncryptionKey() {
		_EncryptionKey = 324;
		return _EncryptionKey;
	}
	static int GetDecryptionKey() {
		return GetEncryptionKey();
	}
	friend class ClsBankClient;
};

