#pragma once
#include <iostream>

using namespace std;
class ClsScreen
{
protected:
	static void _DrawScreenHeader(string Title,string SubTitle="") {
		cout << "\t\t\t\t______________________________________\n\n";
		cout << "\t\t\t\t"<< Title << endl;
		if (SubTitle!="")
		{
			cout << "\n\t\t\t\t" << SubTitle;
		}
		cout << "\n\t\t\t\t______________________________________\n\n";
		
	}
};

