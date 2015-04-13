/*****************************************************************************
 *     Program: Hello World                                                  *
 *      Author: Amrit Panesar <apanesar@coleman.edu>                         *
 *        Date: 08/04/2014                                                   *
 * Description: Display "Hello World" and do a bit of adding and multlipling *
 *****************************************************************************/

#include <conio.h>
#include <string>
#include <iostream>

using namespace std;

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

int main(int argc, char* argv[])
{
	int i, j, k, l = 0;
	while (true)
	{
		cout << "Hello World!" << endl;

		if (pause())
			break;

		cout << "Adding! Please enter two integers." << endl;
		cout << "Number 1: ";
		cin >> i;
		cout << endl;
		cout << "Number 2: ";
		cin >> j;
		cout << endl;
		k = i + j;
		cout << "The result is: " << k << endl;

		if (pause())
			break;

		cout << "Comparing! Please enter two integers." << endl;
		cout << "Number 1: ";
		cin >> i;
		cout << endl;
		cout << "Number 2: ";
		cin >> j;
		cout << endl;
		if ( i == j )
			cout << i << " == " << j << endl;
		else
			cout << i << " != " << j << endl;
		if ( i > j )
			cout << i << " > " << j << endl;
		else if ( i < j )
			cout << i << " < " << j << endl;
		
		if (pause())
			break;


		cout << "Multiplication! Please enter three integers." << endl;
		cout << "Number 1: ";
		cin >> i;
		cout << endl;
		cout << "Number 2: ";
		cin >> j;
		cout << endl;
		cout << "Number 3: ";
		cin >> k;
		cout << endl;
		l = i * j * k;
		cout << "The result is: " << l << endl;

		if (pause())
			break;
	}
	return 0;
}