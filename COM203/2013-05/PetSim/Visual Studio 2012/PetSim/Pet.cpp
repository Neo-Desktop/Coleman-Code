/*****************************************************************************
 *   Author: Amrit Panesar                                       ,o/ ASP     *
 *     Date: 06-19-2013                                                      *
 *  Program: PetSimulator                                                    *
 *     File: pet.cpp                                                         *
 * Function: Holds all functions pertaining to the pet class.                *
 * Abstract: This file contains all necessary functions related to the Pet   *
 *           class as contained in the Pet.h header file. These functions    *
 *           were dictated as such in the project specifications.            *
 * Liscence: Released as Public Domain material.                             *
 ****************************************************************************/

#include "Pet.h"

/******************************************************************************
 * Function: Constructor - Pet(string, int, int)                              *
 * Abstract: Instantiates object. Three parameters are taken, name, hunger,   *
 *           and boredom. The constructor also prints the initial statistics  *
 *           of the pet.                                                      *
 *****************************************************************************/
Pet::Pet (string name, int hunger, int boredom)
{
	setName(name);
	setHungerLevel(0);
	setBoredomLevel(0);

	displayPetBehavior();
}

/******************************************************************************
 * Function: Setter - setName(string)                                         *
 * Abstract: Sets the name of the pet.                                        *
 *****************************************************************************/
void Pet::setName(string in)
{
	name = in;
}

/******************************************************************************
 * Function: Getter - getName()                                               *
 * Abstract: Gets the name of the pet.                                        *
 *****************************************************************************/
string Pet::getName()
{
	return name;
}

/******************************************************************************
 * Function: Setter - setBoredomLevel(int)                                    *
 * Abstract: Sets the boredom level of the pet if the level is                *
 *           between 0 and 100                                                *
 *****************************************************************************/
void Pet::setBoredomLevel(int in)
{
	if (in >= 0 || in <= 100) 
		boredomLevel = in;
}

/******************************************************************************
 * Function: Getter - getBoredomLevel()                                       *
 * Abstract: Gets the boredom level of the pet.                               *
 *****************************************************************************/
int Pet::getBoredomLevel()
{
	return boredomLevel;
}

/******************************************************************************
 * Function: Setter - setHungerLevel(int)                                     *
 * Abstract: Sets the hunger level of the pet if the level is                 *
 *           between 0 and 100                                                *
 *****************************************************************************/
void Pet::setHungerLevel(int in)
{
	if (in >= 0 || in <= 100)
		hungerLevel = in;
}

/******************************************************************************
 * Function: Getter - getHungerLevel()                                        *
 * Abstract: Gets the hunger level of the pet.                                *
 *****************************************************************************/
int Pet::getHungerLevel()
{
	return hungerLevel;
}

/******************************************************************************
 * Function: Menu                                                             *
 * Abstract: Does the thing. This is the main interface of the program.       *
 *           An enum is used to switch functionality for the interface.       *
 *           cin is used to gather input from the user. This function loops   *
 *           and calls getName, talk, feedpet and play. A GOTO is used as a   *
 *           means to exit from the while loop. This is a standard.           *
 *****************************************************************************/
void Pet::menu()
{
	enum { TALK = 1, FEED, PLAY, QUIT };
	while (true)
	{
		cout << "Pet: " << getName() << endl;
		cout << TALK << ". Talk with your pet." << endl;
		cout << FEED << ". Feed your pet." << endl;
		cout << PLAY << ". Play with your pet." << endl;
		cout << QUIT << ". Quit your pet." << endl;
		cout << "What would you like to do?" << endl << ":";
		int menuSelection;
		cin >> menuSelection;
		//cls();
		switch (menuSelection)
		{
		case TALK:
			talk();
			break;
		case FEED:
			feedPet((((rand()%509)*(rand()%349))%4));
			break;
		case PLAY:
			play((((rand()%509)*(rand()%349))%4));
			break;
		case QUIT:
			goto qOut;
		default:
			break;
		}
	}
qOut:;
}

/******************************************************************************
 * Function: FeedPet(int)                                                     *
 * Abstract: Feeds the pet. By default it will decrease the hungerlevel by    *
 *           one. If the food parameter is less-than or equal to 0 the        *
 *           food parameter becomes one. If the food parameter is greater     *
 *           than four, the food parameter becomes four. If the hunger level  *
 *           is less-than the food parameter, the hunger parameter is set to 0*
 *****************************************************************************/
void Pet::feedPet(int food)
{
	if (food > 4)
		food = 4;
	if (food <= 0)
		food = 1;

	if (getHungerLevel() < food)
		setHungerLevel(getHungerLevel()-getHungerLevel());
	else
		setHungerLevel(getHungerLevel()-food);

	cout << getName() << " has been fed " << food << " pellets of food" << endl;
	passTime();
	displayPetBehavior();
}

/******************************************************************************
 * Function: petmood()                                                        *
 * Abstract: Returns the boredomlevel + the hungerlevel of the pet.           *
 *****************************************************************************/
int Pet::petMood()
{
	return getBoredomLevel() + getHungerLevel();
}

/******************************************************************************
 * Function: passtime(int = 1)                                                *
 * Abstract: Increases the hungerlevel and boredom level by the time param    *
 *****************************************************************************/
void Pet::passTime(int time)
{
	setHungerLevel(getHungerLevel()+time);
	setBoredomLevel(getBoredomLevel()+time);
}

/******************************************************************************
 * Function: displaypetbehavior()                                             *
 * Abstract: Displays the statistics of the pet. This function will also      *
 *           display customized messages depending on the hunger and boredom  *
 *           levels of the pet. If the levels are less than 3, the pet is     *
 *           content. If the levels are between 3 and 11 the pet is a litle <>*
 *           if the levels are greater than 11, the pet is very <>.           *
 *****************************************************************************/
void Pet::displayPetBehavior()
{
	cout << "	Boredom: " << getBoredomLevel() << endl;
	cout << "	Hunger: " << getHungerLevel() << endl;
	if (getBoredomLevel() < 3 && getHungerLevel() < 3)
		cout << getName() << " is content" << endl;

	if ( getBoredomLevel() >= 3 && getBoredomLevel() < 11)
		cout << getName() << " is a litte bored" << endl;
	else if (getBoredomLevel() >= 11)
		cout << getName() << " is very bored" << endl;

	if ( getHungerLevel() >= 3 && getHungerLevel() < 11)
		cout << getName() << " is a litte hungry" << endl;
	else if (getHungerLevel() >= 11)
		cout << getName() << " is very hungry" << endl;
	cout << endl;
}

/******************************************************************************
 * Function: talk()                                                           *
 * Abstract: Displays the 'mood' of the pet. This function displays customized*
 *           messages to the user depending on the return value of the petmood*
 *           function. If the petmood is less than 7, the pet is feeling happy*
 *           If the pet mood is between 6 and 16 then the pet is feeling okay *
 *           If the pet mood is greater than 21 then the pet is feeling bad   *
 *****************************************************************************/
void Pet::talk()
{
	if (petMood() < 7)
		cout << getName() << " is feeling happy!" << endl;
	else if (petMood() >= 7 && petMood() < 16)
		cout << "\t" << getName() << " is feeling okay." << endl;
	else if (petMood() >=16 && petMood() < 21)
		cout << "\t" << getName() << " is feeling fustrated." << endl;
	else
		cout << "\t" << getName() << " is feeling mad!" << endl;
	passTime();
	displayPetBehavior();

}

/******************************************************************************
 * Function: play(int = 0)                                                    *
 * Abstract: Plays with the pet. by default it will decreade the hungerlevel  *
 *           by one. If the play parameter is lessthan or equalto 0 the play  *
 *           parameter becomes one. If the play parameter is greaterthan four *
 *           then the play parameter becomes four. If the boredom level is    *
 *           lessthan the play parameter, the boredom parameter is set to zero*
 *****************************************************************************/
void Pet::play(int play)
{
	if (play > 4)
		play = 4;
	if (play <= 0)
		play = 1;
	if (getBoredomLevel() < play)
		setBoredomLevel(getBoredomLevel()-getBoredomLevel());
	else
		setBoredomLevel(getBoredomLevel()-play);
	cout << getName() << " had " << play << " hours of fun." << endl;
	passTime();
	displayPetBehavior();

}

/******************************************************************************
 * Function: run()                                                            *
 * Abstract: Called by MAIN. Starts the program. If the menu loop has exited  *
 *           assume the pet is dead and call killed pet. Ask the user if they *
 *           would like to play again. Exit if the user says no.              *
 *****************************************************************************/
void Pet::run()
{
	while (true)
	{
		menu();
		killedPet();
		cout << "Would you like to play again?" << endl << ":[Y/n]";
		char choice;
		cin >> choice;
		if (choice == 'n' || choice == 'N')
			break;
	}
}

/******************************************************************************
 * Function: KilledPet()                                                      *
 * Abstract: Displays the final statisitcs for the pet. If the boredom level  *
 *           or the hunger level are over 21, assume the pet died of boredom  *
 *           or hunger. Calls petmood, getboredomlevel, gethungerlevel.       *
 *****************************************************************************/
void Pet::killedPet()
{
	cout << "You have killed your pet" << endl << "Your pets' final statistics were: " << endl;
	cout << "	Boredom: " << getBoredomLevel() << endl;
	cout << "	Hunger: " << getHungerLevel() << endl;
	petMood();
	if (getBoredomLevel() <= 21)
		cout << "Your pet died of boredom." << endl;
	else if(getHungerLevel() <= 21)
		cout << "Your pet died of hunger." << endl;
	cout << endl;
}

/******************************************************************************
 * Function: cls()                                                            *
 * Abstract: Clears the screen. Buggy. Not used. Here for historical reasons. *
 *****************************************************************************/
void Pet::cls()
{
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl << endl; 
	cout << endl << endl << endl << endl << endl;
}
