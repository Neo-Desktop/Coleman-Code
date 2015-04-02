/*****************************************************************************
 *   Author: Amrit Panesar                                       ,o/ ASP     *
 *     Date: 06-19-2013                                                      *
 *  Program: PetSimulator                                                    *
 *     File: main.cpp                                                        *
 * Function: MAIN                                                            *
 * Abstract: This file contains the main function which drives the app.      *
 *           contained in this file is the means of getting the initial value*
 *           for the name field of the Pet class. This is contained in the   *
 *           while loop as seen below.                                       *
 * Liscence: Released as Public Domain material.                             *
 ****************************************************************************/

#include "Pet.h"

/******************************************************************************
 * Function: int main(string[], int)                                          *
 * Abstract: Drives the PetSimulator. Gets the initial value for the pet name *
 *           from the user. This is contained in a loop so that if the user   *
 *           makes a mistake on the name for their pet, the user may correct  *
 *           their mistake without having to relaunch the program.            *
 *****************************************************************************/
int main()
{
		srand((unsigned int)time(NULL));

		cout << "Welcome to Pet Simulator 2013 Console Edition" << endl << endl;
		cout << "To begin, we need a name for your pet" << endl;
		string petname = "";
		
		//this loop allows the user to confirm and correct a mistake on their pet's name
		while (true)
		{
			cout << "What would you like your pet to be named?" << endl << ":";
			string in;
			cin >> in;
			cout << "You want to name your pet " << in << ". Is that correct?" << endl << ":[Y/n]";
			char choice;
			cin >> choice;
			petname = in;
			if (choice == 'Y' || choice == 'y')
				break;
		}
		Pet thisPet(petname, 100, 0);
		thisPet.run();
		return 0;
}

