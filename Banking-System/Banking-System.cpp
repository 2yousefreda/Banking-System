#include <iostream>

#include "ClsPerson.h"
#include "ClsDate.h"
#include "ClsInputValidate.h"
#include "ClsString.h"
#include "ClsUtility.h"

using namespace std;
int main()
{

	ClsPerson person("yousef", "reda", "0101", "rer.ecf");
	cout << person.Phone;

}