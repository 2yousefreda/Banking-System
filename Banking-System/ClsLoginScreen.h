#pragma once
#include "ClsScreen.h"
#include "ClsMainScreen.h"
#include "Global.h"
using namespace std;
class ClsLoginScreen : protected ClsScreen
{

	static bool _Login() {
		short Counter = 0;
		bool LoginFaild = false;
		string Username, password;
		do
		{
			if (LoginFaild)
			{
				if (Counter!=3)
				{
					Counter++;
					cout << "\n\nInvlaid Username/Password\n";
					cout << "You have " << 3 - Counter << " time to login\n\n";
				}
				else if(Counter==3)
				{
					
					return false ;
				}
				
			}
			cout << "\n\nEnter Username : ";
			cin >> Username;
			cout << "\nEnter Password : ";
			cin >> password;
			CurrentUser = ClsUser::Find(Username, password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);
		CurrentUser.RegisterLogin();
		ClsMainScreen::ShowMainMenu();
	}
public:
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t   Login Screen","",false);
		return _Login();
	}
};

