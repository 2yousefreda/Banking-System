#pragma once
#include <iostream>
#include <string>
using namespace std;
class EncryptionKey
{



	static int _EncryptionKey;
public:
	EncryptionKey() {
	}
	static int GetEncryptionKey() {
		_EncryptionKey = 324;
		return _EncryptionKey;
	}
	static int GetDecryptionKey() {
		return GetEncryptionKey();
	}

};