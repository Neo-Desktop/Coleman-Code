#include "stdhangman.h"

// Pause() use conio.h's get character to pause the program
void pause()
{
	int c;
	cout << endl << "Press any key to continue . . ." << endl;
	c = _getch();
	if (c == 0 || c == 224) // getch will return a 0 or 244 on error
	{
		_getch(); // try again
	}
}

// cursorpos(X,Y) use ConsoleAPI to place the cursor at a particular position
void cursorpos(int X, int Y)
{
	if ( X < 0 ) // off the screen
	{
		X = 0;
	}
	if ( Y < 0 )
	{
		Y = 0;
	}
	HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE ); //grab the stdout handle
	COORD newpos = { X, Y };  // use the Coord struct to stage the new position
	SetConsoleCursorPosition( hStdOut, newpos ); // set the new cursor position
}

// take the input modulus the length by 80, set the cursor position there
void centerline(string input, int linenum)
{
	if (input.length() > 80) // over 80 characters? must be centred already
	{
		cursorpos(0,linenum);
	}
	int mod = (80-input.length())/2; // formula: input length subtracted from console line length divided by 2
	cursorpos(mod,linenum); // set where to write
	cout << input << endl; // write it
}

// write a line
void writeline(string input)
{
	cout << ' ' << input << endl; // simple function to begin a line with a ' '
}

// write a blank line
void writeline(int num)
{
	for (int i = 0; i <= num; i++) // easy function for multiple blank lines
	{
		cout << endl;
	}
}

// do the separator thing
void drawseperator()
{
	for (int i = 2; i < 24; i++) // separates the hangman from the words
	{
		cursorpos(50,i);
		cout << "|";
	}
}

// seed using micro time. much better than grabbing a random pointer.
void doseed()
{
	unsigned __int64 freq;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	double timerFrequency = (1.0/freq);

	unsigned __int64 startTime;
	QueryPerformanceCounter((LARGE_INTEGER *)&startTime);
	srand(startTime*freq);
}

// use the console api to fill the screen with spaces
void cls() {
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {0, 0};
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO screen_attr;
	unsigned size;

	GetConsoleScreenBufferInfo(screen, &screen_attr);

	size = screen_attr.dwSize.X * screen_attr.dwSize.Y;
	FillConsoleOutputCharacterW(screen, ' ', size, pos, &written);
	
	SetConsoleCursorPosition(screen, pos);
}
