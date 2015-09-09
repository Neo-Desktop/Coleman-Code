#include "Helper.h"

void pause() {
	printf("\n%s\n", "Press any key to continue. . .");
	getch();
}

void clrscr() {
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };
	COORD                      consoleSize = { 24, 80 };
	COORD                      consoleWipe = { 0, 0 };
	int                        minx;
	int                        miny;

	minx = GetSystemMetrics(SM_CXMIN);
	miny = GetSystemMetrics(SM_CYMIN);

	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	// Get the number of cells in the current buffer
	if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;
	consoleSize = csbi.dwSize;

	
	if (!SetConsoleScreenBufferSize(hStdOut, consoleWipe)) {
		return;
	}
	/*
	if (!SetConsoleScreenBufferSize(hStdOut, consoleSize)) {
		return;
	}
	*/

	// Fill the entire buffer with spaces
	if (!FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', cellCount, homeCoords, &count)) return;
  
	// Fill the entire buffer with the current colors and attributes
	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) return;

	// Move the cursor home
	SetConsoleCursorPosition( hStdOut, homeCoords );
 }