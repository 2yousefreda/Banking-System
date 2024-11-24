#include <iostream>

#include "ClsPerson.h"
#include "ClsDate.h"
#include "ClsInputValidate.h"
#include "ClsString.h"
#include "ClsUtility.h"
#include "ClsBankClient.h"

using namespace std;
int main()
{

	 ClsBankClient client=ClsBankClient::Find("122");
	 ClsBankClient client1=ClsBankClient::Find("111","12");
	 client.print();
	 client1.print();

}