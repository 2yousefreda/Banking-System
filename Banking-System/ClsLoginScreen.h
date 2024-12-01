#pragma once
#include "ClsScreen.h"
#include "ClsMainScreen.h"
#include "Global.h"
using namespace std;
class ClsLoginScreen : protected ClsScreen
{
	static void _Login() {
		bool LoginFaild = false;
		string Username, password;
		do
		{
			if (LoginFaild)
			{
				cout << "\n\nInvlaid Username/Password\n\n";
			}
			cout << "\n\nEnter Username : ";
			cin >> Username;
			cout << "\nEnter Password : ";
			cin >> password;
			CurrentUser = ClsUser::Find(Username, password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);
		ClsMainScreen::ShowMainMenu();
	}
public:
	static void ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t   Login Screen","",false);
		_Login();
	}
};

