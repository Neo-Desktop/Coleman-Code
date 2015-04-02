#define _CRT_SECURE_NO_WARNINGS

#include "stdhangman.h"
#include "main.h"
#include "resource.h"

using namespace std;

int main()
{
	ConsoleSetup(TEXT("Hangman"));
	Hangman game;
	game.displayMenu();

	cout << "Thanks for playing!" << endl << endl;
	pause();
	return 0;
}

/* ------------------------------------------- Just boring stuff after here ------------------------ */

void ConsoleSetup(TCHAR* input)
{
	system("color 1e");

	ChangeConsoleIcon(IDI_ICON1);
	ChangeConsoleTitle(input);
	cout << string(80,'*') << "Welcome to ";
	wcout << input;
	cout << " " << GetYear() << " Edition!" << endl << string(80,'*') << endl << endl;
}

void ChangeConsoleTitle (const TCHAR* input)
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	TCHAR szNewTitle[MAX_PATH];
	TCHAR szYear[7];

	StringCchCopy(szNewTitle, MAX_PATH, TEXT(" "));
	StringCchCat(szNewTitle, MAX_PATH, input);

	StringCchPrintf(szYear, 7, TEXT(" %d!"), GetYear());
	StringCchCat(szNewTitle, MAX_PATH, szYear);

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