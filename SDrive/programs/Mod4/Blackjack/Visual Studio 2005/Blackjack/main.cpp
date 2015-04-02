#include "Blackjack.h"

int main()
{
	string name;
	while (true)
	{
		cout << "Welcome to Blackjack 77260" << endl;
		cout << "What is your name?" << endl << ":";
		cin >> name;
		getch();
	}
	while (true)
	{
		Game game(const string &name);
		if (game.play())
		{
			break;
		}
	}
}
