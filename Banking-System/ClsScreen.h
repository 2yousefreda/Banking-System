#pragma once
#include <iostream>
#include "ClsDate.h"
#include "Global.h"

using namespace std;
class ClsScreen
{
protected:
	static void _DrawScreenHeader(string Title,string SubTitle="",bool IsNotLoginScreen=true) {
		
			
		cout << "\t\t\t\t______________________________________\n\n";
		cout << "\t\t\t\t"<< Title << endl;
		if (IsNotLoginScreen)
		{

		cout << "\n User :  "<< CurrentUser.UserName << endl;
		}
		if (SubTitle!="")
		{
			cout << "\n\t\t\t\t" << SubTitle;
		}
		cout << "\n\t\t\t\t______________________________________\n\n";
		
		
		
	}
	static bool ChickAccessRights(ClsUser::enPermission Permission) {
		if (!CurrentUser.ChickAccessPermission(Permission))
		{
			cout << "\t\t\t\t______________________________________\n\n";
			cout << "\n\t\t\t\t   Access Denid! Contact your Admin  " ;
			cout << "\n\t\t\t\t______________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}
	}
};

