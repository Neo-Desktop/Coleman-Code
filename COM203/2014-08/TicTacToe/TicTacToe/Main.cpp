/******************************************************************************
 * Project Two: Tic-Tac-Toe                                                   *
 *      Author: Amrit Panesar                                                 *
 *        Date: 08/20/2014                                                    *
 *     License: Released into the Public Domain                               *
 *****************************************************************************/

#include "includes.h"
#include "main.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ConsoleSetup("Tic-Tac-Toe");

	string name = "";
	while (name.length() == 0)
	{
		cout << "Please enter your name" << endl << ": ";
		cin >> name;
		bool breakin = false;
		while (!breakin)
		{
			cout << "Your name is: "<< name << endl << "Is this correct? " << endl << "[Y/n]: ";
			int in = _getch();
			cout << (char)in << endl;
			switch (toupper(in))
			{
			case 'Y':
				breakin = true;
				break;

			case 'N':
				breakin = true;
				name = "";
				break;
			}
			system("cls");
		}
	}

	char player = ' ';
	while (player == ' ')
	{
		cout << "Please enter one character for your board marker" << endl << ": ";
		player = _getch();
		cout << player << endl;
		bool breakin = false;
		while (!breakin)
		{
			cout << "Your marker is: "<< player << endl << "Is this correct? " << endl << "[Y/n]: ";
			int in = _getch();
			cout << (char)in << endl;
			switch (toupper(in))
			{
			case 'Y':
				breakin = true;
				break;

			case 'N':
				breakin = true;
				player = ' ';
				break;
			}
			system("cls");
		}
	}

	char computer = ' ';
	if (player == 'X')
		computer = 'O';
	else
		computer = 'X'; 
	
	TicTacToe t = TicTacToe(name, player, computer);

	while (true)
	{
		t.run();
		cout << "Would you like to play again?" << endl << "[Y/n]: ";
		char hold = toupper(_getch());
		cout << hold << endl;
		if (hold == 'Y' || hold == 'N' || hold == LF || hold == ESC)
		{
			if (hold == 'N' || hold == ESC)
				break;
		}
		else
		{
			cout << "Please enter either Y or N." << endl;
			continue;
		}
	}

	cout << "Game Over." << endl << endl;
	cout << "Press any key to continue..." << endl;
	_getch();

}

void ConsoleSetup(char* input)
{
	system("color 1e");

	ChangeConsoleIcon(IDI_ICON1);
	ChangeConsoleTitle(input);
	cout << string(80,'*') << "Welcome to " << input << " " << GetYear() << " Edition!" << endl << string(80,'*') << endl << endl;
}

void ChangeConsoleTitle (const char* input)
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	TCHAR szNewTitle[MAX_PATH];

	StringCchPrintf(szNewTitle, MAX_PATH, TEXT("%s %d"), input, GetYear());
	SetConsoleTitle(szNewTitle);
}

void ChangeConsoleIcon (const int resource_number)
{
	HMODULE hMainMod = GetModuleHandle(0);
	assert (hMainMod);
 
	HICON hMainIcon = ::LoadIcon(hMainMod, MAKEINTRESOURCE(resource_number));
	assert (hMainIcon);

	// Load kernel 32 library
	HMODULE hMod = LoadLibrary( _T( "Kernel32.dll" ));
	assert (hMod);
 
	// Load console icon changing procedure
	typedef DWORD (__stdcall *SCI)(HICON);
	SCI pfnSetConsoleIcon = reinterpret_cast<SCI>(GetProcAddress(hMod, "SetConsoleIcon"));
	assert (pfnSetConsoleIcon);
 
	// Call function to change icon
	pfnSetConsoleIcon (hMainIcon);
 
	FreeLibrary (hMod);
}// End ChangeIcon

int GetYear()
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);

	return timePtr->tm_year + 1900;
}