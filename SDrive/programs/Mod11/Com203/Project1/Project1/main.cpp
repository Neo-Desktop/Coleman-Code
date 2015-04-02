/*****************************************************************************
 *     Program: player                                                       *
 *      Author: Amrit Panesar <apanesar@coleman.edu>                         *
 *        Date: 08/04/2014                                                   *
 * Description: Setup, instantiate, and access player functions              *
 *****************************************************************************/

#include <string>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "Player.h"

using namespace std;

bool pause();

int main(const char* argv, int argc)
{

	srand((unsigned int) time(NULL));

	string in;
	char choice;

	while (true)
	{
		cout << "What would you like your player to be named?" << endl << ":";
		cin >> in;
		
		while (true) {
			cout << "You want to name your player " << in << ". Is that correct?" << endl << ":[Y/n] ";
			int i = getch();
			if ((char)i == 'y' || (char)i == 'Y' || (char)i == 'n' || (char)i == 'N' )
			{
				choice = i;
				break;
			}
			cout << "Please enter either Y or N" << endl << ":[Y/n] ";
		}
		if (choice == 'Y' || choice == 'y' || choice == 'n' || choice == 'N')
			break;
	}

	while (choice == 'Y' || choice == 'y')
	{
		Player p1((((rand()%509)*(rand()%349))%101), (((rand()%509)*(rand()%349))%101), in);
		cout << p1.getName() << " recieved " << p1.getScore() << " points with " << p1.getHealth() << " points of health!" << endl << endl;

		while (true)
		{
			while (true) {
				cout << "Would you like to play again? " << endl << ":[Y/n] ";
				int i = getch();
				if ((char)i == 'y' || (char)i == 'Y' || (char)i == 'n' || (char)i == 'N' )
				{
					choice = i;
					break;
				}
				cout << "Please enter either Y or N" << endl;
			}
			if (choice == 'Y' || choice == 'y' || choice == 'n' || choice == 'N')
				break;
		}
		cout << endl;
		if (choice == 'n' || choice == 'N')
		{
			break;
		}
	}
	pause();
}

bool pause()
{
	enum { NUL = 0, SOH, STX, ETX, EOT, ENQ, ACK, BEL, BS, HT,
	   LF, VT, FF, CR, SO, SI, DLE, DC1, DC2, DC3, DC4, NAK, 
	   SYN, ETB, CAN, EM, SUB, ESC, FS, GS, RS, US, DEL = 127 };

	cout << "Press any key to continue..." << endl << endl;
	int i = getch();
	if ( i == ETX || i == ESC ) // control + c || escape
	{
		return true;
	}
	return false;
}