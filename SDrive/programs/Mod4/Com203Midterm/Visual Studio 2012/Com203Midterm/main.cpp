/*****************************************************************************
 *  Program: Banking Application Midterm                                     *
 *   Author: Amrit Panesar                                                   *
 *     Date: 06/26/2013                                                      *
 *   Course: COM 203 - S. Ganore                                             *
 * Abstract: A bank account class with methods to deposit, withdraw,         *
 *           and check the balance of the account instance                   *
 *  Depends: Account.h, Standard C Library                                   *
 *     File: main.cpp                                                        *
 * Descript: This file contains the main method for the Banking application  *
 *           it prompts the user for a name, seeds the random function, and  *
 *           creates an instance of the Account class.                       *
 *           For more information see Account.cpp and Account.h              *
 *****************************************************************************/

#include "Account.h"

int main()
{
	//even though there is No need to use rand function, I find it easier.
	srand((unsigned int)time(NULL));

	//some place to store the name
	string accountName;

	//begin name choosing loop.
	while (true)
	{
		cout << "Welcome to the Bank Account program" << endl;
		cout << "What is your name?" << endl << ":";
		cin >> accountName;
		cout << "Your name is " << accountName << ". Is that correct?" << endl << "[Y/n]:";
		char choice;
		cin >> choice;
		if (toupper(choice) == 'Y') // toupper() because Yes, yes, Y and y will all be converted to Y
		{
			break;
		}
	}
	
	Account acc(accountName);
	acc.run();

	system("pause"); // a call to Windows.h, makes the pause thingy
	return 0; //success
}