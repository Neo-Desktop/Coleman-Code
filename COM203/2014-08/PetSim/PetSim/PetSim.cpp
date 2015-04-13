// PetSim.cpp : Defines the entry point for the console application.
//

#include "stdhead.h"


bool yorn();
void ChangeIcon( const HICON hNewIcon );

int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	TCHAR szNewTitle[MAX_PATH];
	
	HMODULE hMainMod = GetModuleHandle( 0 );
	assert( hMainMod );
 
	HICON hMainIcon = ::LoadIcon( hMainMod, MAKEINTRESOURCE( IDI_ICON1 ));
	assert( hMainIcon );
 
	// Change main window icon
	ChangeIcon( hMainIcon );
 
	system("color 1e");
	StringCchPrintf(szNewTitle, MAX_PATH, TEXT("Pet Simulator %d"), timePtr->tm_year + 1900);
	SetConsoleTitle(szNewTitle);
	
	cout << string(80, '*');
	cout << "Welcome to Pet Simulator " << timePtr->tm_year + 1900 << " Edition!" << endl << endl;
	cout << string(80, '*');

	bool named = false;
	string name;

	while(!named)
	{
		cout << endl << endl;
		cout << "Step one: Name your pet." << endl;
		cout << "It's time to name your pet! Please enter a name for your pet" << endl << ": ";
		cin >> name;
		cout << "You've named your pet: " << name << endl << endl;
		cout << "Is this correct?" << endl << "[Y/n]: ";
		i = getch();
		cout << (char)i << endl;
		bool breakout = false;
		if ( i == 89 || 121 || 13 || 27 || 28 || 110)
		{
			switch (i)
			{
			case 89:
			case 121:
			case 13:
				named = true;
				breakout = true;
				break;
			case 27:
			case 28:
			case 110:
				breakout = true;
				break;
			}
		}
		if (!breakout)
		{
			if (yorn())
			{
				named = true;
				breakout = true;
			}
			else
			{
				breakout = true;
			}
		}
	}


	Pet pet = Pet(name);
	
	bool breakout = false;
	while(!breakout)
	{
		pet.menu();
		system("cls");
		cout << "Would you like to play again?" << endl << "[Y/n]: ";
		i = getch();
		cout << (char)i << endl;
		bool bjorn = false;
		if ( i == 89 || 121 || 13 || 27 || 28 || 110)
		{
			switch (i)
			{
			case 89:
			case 121:
			case 13:
				bjorn = true;
				breakout = false;
				break;
			case 27:
			case 28:
			case 110:
				bjorn = true;
				breakout = true;
				break;
			default:
				bjorn = false;
			}
		}
		if (!bjorn)
		{
			if (yorn())
			{
				breakout = false;
			}
			else
			{
				breakout = true;
			}
		}
	}

	system("cls");
	cout << "Game over .." << endl << endl;
	cout << "Press any key to continue...";
	getch();

	return 0;
}

bool yorn()
{
	int i = 0;
	while (i != 0)
	{
		cout << "Please enter Y or N :" << endl;
		i = getch();
		cout << (char)i << endl;
		switch (i)
		{
		case 89:
		case 121:
			return true;
			break;
		case 28:
		case 110:
			return false;
			break;
		default:
			i = 0;
		}
	}

	ChangeIcon( 0 );
}

void ChangeIcon( const HICON hNewIcon )
{
   // Load kernel 32 library
   HMODULE hMod = LoadLibrary( _T( "Kernel32.dll" ));
   assert( hMod );
 
   // Load console icon changing procedure
   typedef DWORD ( __stdcall *SCI )( HICON );
   SCI pfnSetConsoleIcon = reinterpret_cast<SCI>( GetProcAddress( hMod, "SetConsoleIcon" ));
   assert( pfnSetConsoleIcon );
 
   // Call function to change icon
   pfnSetConsoleIcon( hNewIcon );
 
   FreeLibrary( hMod );
}// End ChangeIcon
