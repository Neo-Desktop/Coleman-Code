
/***************************************************************
 * Project: COM 203 Midterm
 *  Author: Amrit Panesar
 *    Date: 09/04/2014
 **************************************************************/

/***************************************************************
NOTE: Minimum requirement to qualify for grading:
	1) Code must be properly indented, modularized and follows the best practices.

Account Class (A bank account class with methods to deposit, withdraw, and check the balance.) (5 points)
1. Class contains 3 private data members called accountBalance, accountName and accountNum.
	Choose appropriate data types for these variables

2. Write an overloaded constructor that takes one parameter of the type string.
	The constructor initializes the accountName with the parameter specified.
	The member variables accountBalance and accountNum are assigned some random value (No need to use rand function).

3. Write appropriate destructor, set, get and display functions.

4. The class will also contain member functions named menu, withdraw, and deposit
	The withdraw function checks to see if balance is sufficient for withdrawal.
	If so, decrements balance by amount; if not, prints an appropriate message indicating insufficient funds and displays the current balance.
	The deposit function adds deposit amount to balance and displays new balance
	The menu function will contain the following menu options: 1. Check Balance, 2. Deposit Amount, 3. Withdraw Amount, 4. Exit.
	Use appropriate messages for each option selected and then call the correct function to perform the task.
*****************************************************************/


#include "includes.h"
#include "account.h"
#include "main.h"
#include "resource.h"


int _tmain(int argc, _TCHAR* argv[]) // _tmain you say? yes. its windows.
{
	ConsoleSetup("COM203 Midterm");
	pause();
	cls();

	/*--------------------------------------------------- lets begin ----------------------------*/

	string name = "";
	bool named = false;
	while (!named)
	{
		cout << string(80, '*') << endl;
		// lets ask for the user's name
		cout << "Welcome to the Bank Account program" << endl << endl;
		cout << string(10, ' ') << string (15, '-') <<  endl;
		cout << "Please enter your name" << endl << ":";
		cin >> name;
		cout << name << endl << endl;
		if (!name.empty()) // ensure they didn't just hit enter (although cin doesn't allow for that by default)
		{
			cout << "Your name is: " << name << ". Is this correct?" << endl << "[Y/n]: ";
			char charin = 0;
			while (charin == 0) // yes, no, esc, or enter are acceptable
			{
				charin = _getch();
				cout << charin;
				if (charin != CR && charin != ESC)
				{
					switch (toupper(charin))
					{
					case 'Y':
						named = true;
						break;
					case 'N':
						named = false;
						break;
					default:
						charin = 0;
						break;
					}
				}
				else if (charin == ESC) // special case for escape, just quit
				{
					return 0;
				}
				else // continue on
				{
					named = true;
				}
				
			}
		}
		cls();
	}

	randSeed(); // seeeeeeed
	account a = account(name); // make a new account object
	a.menu(); // start the menu


	// endings
	cls();
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "Thank you for using Banking program, " << name << ", please come again!" << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	pause();
}



/******************************* Just some fancy windows stuff below here *****************************/

void ConsoleSetup(char* input)
{
	system("color 1e"); // change the background color to yellow on blue

	ChangeConsoleIcon(IDI_ICON1); // change the console icon to the icon defined in resources.h
	ChangeConsoleTitle(input); // change the console title
	cout << string(80,'*') << "Welcome to " << input << " " << GetYear() << " Edition!" << endl << string(80,'*') << endl << endl; // display the title screen.
}

void ChangeConsoleTitle (const char* input)
{
	time_t t = time(NULL); // get current timestamp
	tm* timePtr = localtime(&t); // using the timezone the system is in
	TCHAR szNewTitle[MAX_PATH]; // console title can only be as long as the maximum path length defined in windows

	size_t newsize = strlen(input) + 1; // input plus null char
	wchar_t * wcstring = new wchar_t[newsize]; // make a new pointer on the heap for storing the title
	size_t convertedChars = 0; // number of characters converted to the above structure
	mbstowcs_s(&convertedChars, wcstring, newsize, input, _TRUNCATE); // make it happen

	StringCchPrintf(szNewTitle, MAX_PATH, TEXT("%s %d %s"), wcstring, GetYear(), TEXT("edition")); // move the texts into the TCHAR field
	SetConsoleTitle(szNewTitle); // set the console title
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

void pause()
{
	cout << "Press any key to continue. . ." << endl;
	_getch();
}

void cls()
{
	system("cls");
}

void randSeed()
{
	time_t t = time(NULL);
	srand(t);
}

string spacePad(int input, int length, bool right)
{
    ostringstream ss;
	if (!right)
		ss << left << setw( length ) << setfill( ' ' ) << input;
	else
		ss << right << setw( length ) << setfill( ' ' ) << input;
    return ss.str();
}