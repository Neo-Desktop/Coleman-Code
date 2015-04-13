#include "Tic_Tac_Toe.h"


int main()
{
	Tic_Tac_Toe ttt;
	while (true)
	{
		ttt.run();
		cout << endl << "Would you like to play again?" << endl << "[Y/n]:";
		string input;
		cin >> input;
		if (toupper(input[0]) != 'Y')
		{
			break;
		}
	}
	return 0;
}