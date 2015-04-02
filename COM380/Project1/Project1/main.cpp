
/***********************************************
 * Project 1 - COM380 - S. Mayer
 * By: Amrit Panesar - 77260
 * Towers of Hanoi
 ***********************************************/

#include "main.h"
using namespace std;

// Not unicode safe
// who wants to use silly wide characters anyways
int main(int argc, char* argv[])
{
#ifdef _WIN32

	// Remember how things were when we started
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi );
	SetConsoleTextAttribute( hstdout, 0x1E );
	ClearScreen();

#endif // _WIN32

	vector<Tower> tvecs;
	int towers = 3;
	int discs = 5;

	cout << "Before we begin, how many discs would you like to solve for?" << endl;
	int num = 0;
	while (num < 3)
	{
		cout << "Please enter a number greater than three" << endl << ": ";
		string hold = "";
		cin >> hold;
		istringstream ss(hold);
		ss >> num;
		if (ss.fail())
		{
			cout << "Error: invalid integer specified, please try again." << endl;
		}
		else if (num < 3)
		{
			cout << "Error: Please specify an integer greater than three" << endl;
			num = 0;
		}
	}
	cout << "Input accepted." << endl;
	cout << "Creating "<< num << " discs." << endl;
	discs = num;

	for (int i = 0; i < towers; i++)
	{
		tvecs.push_back(Tower(discs, i));
	}
	tvecs.at(0).setAll();

	cout << "Initial state: " << endl << endl;
	println(tvecs);
	if (discs > 11)
	{
		cout << endl;
		cout << "Disclaimer: As you can see, with a disc count higher than 11, it looks crappy." << endl;
		cout << "Please use the Console2 program (or Windows PowerShell) for a better experiance" << endl;
		cout << endl;
	}
	pause();
	ClearScreen();
	creepyLoop("Towers of Hanoi");

	int totalMoves = movePieces(tvecs, discs - 1, 0, 2, 1, 0);

	pause();
	ClearScreen();
	cout << "Final state: " << endl << endl;
	println(tvecs);

	cout << "Finished with " << totalMoves << " moves." << endl;

	cout << endl << endl;
	cout << "Thanks for playing!" << endl;
	pause();

#ifdef _WIN32
	SetConsoleTextAttribute( hstdout, csbi.wAttributes);
#endif // _WIN32

	return 0;
}

void println(vector<Tower> &tvecs)
{
	int discs = tvecs.at(0).getdnum();
	int towers = tvecs.size();
	for (int i = 0; i < discs + 1; i++)
	{
		for (int j = 0; j < towers; j++)
		{
			tvecs.at(j).println(i);
		}
		cout << endl;
	}
	cout << endl;
}

int movePieces(vector<Tower> &tvecs, int currentStack, int from, int to, int helper, int moveaccumulator)
{
	moveaccumulator++;
	if (currentStack == 0)
	{
		tvecs.at(from).setAt(currentStack, false);
		tvecs.at(to).setAt(currentStack, true);
		println(tvecs);
	}
	else
	{
		moveaccumulator = movePieces(tvecs, currentStack - 1, from, helper, to, moveaccumulator);
		tvecs.at(from).setAt(currentStack, false);
		tvecs.at(to).setAt(currentStack, true);
		println(tvecs);
		moveaccumulator = movePieces(tvecs, currentStack - 1, helper, to, from, moveaccumulator);
	}
	return moveaccumulator;
}

void creepyLoop(string input)
{
	int num  = input.length() + 12;
	string diffs = centerLine(num);

	cout << diffs << input << " ";
	sleep(500);
	cout << ".";
	sleep(500);
	cout << " ";
	sleep(500);
	cout << ".";
	sleep(500);
	cout << " ";
	sleep(500);
	cout << ".";
	cout << endl << endl;
}

string centerLine(string in)
{
	int len = in.length();
	return centerLine(len);
}

string centerLine(int len)
{
	int diff = (len % 80)/2;
	string strDiff = "";
	for (int i = 0; i < len; i++)
	{
		strDiff += " ";
	}
	return strDiff;
}

void pause()
{
	cout << "Press any key to continue . . .";
	_getch(); // silly posix..
	cout << endl;
}

void sleep(int in)
{
#ifdef _WIN32
	Sleep(in);
#elif __linux__
	usleep(in);
#endif
}

void ClearScreen()
{
#ifdef _WIN32

	HANDLE conOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if (conOut == INVALID_HANDLE_VALUE)
		return;

	DWORD count, cellCount;

	//Get the number of cells in the current buffer
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(conOut, &csbi))
		return;

	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	//Fill the entire buffer with spaces
	COORD origin = { 0, 0 };
	if (!FillConsoleOutputCharacter(conOut, (TCHAR) ' ', cellCount, origin, &count))
		return;

	//Fill the entire buffer with the current colors and attributes
	if (!FillConsoleOutputAttribute(conOut, csbi.wAttributes, cellCount, origin, &count))
		return;

	//Move the cursor to 0,0
	SetConsoleCursorPosition(conOut, origin);

#elif __linux__

	if (!cur_term)
    {
		int result;
		setupterm (NULL, STDOUT_FILENO, &result);
		
		if (result <= 0)
			return;
    }
	putp(tigetstr("clear" ));

#endif
}

