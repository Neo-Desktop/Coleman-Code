
/******************************************************************************
 * Pet.cpp - Define a pet object                                              *
 *  Author: Amrit Panesar <apanesar@coleman.edu>                              *
 *    Date: 08/18/2014                                                        *
 * License: Released into public domain                                       *
 *****************************************************************************/

#include "stdhead.h"

/****************************************** Getters and Setters **************/

int Pet::getHungerLevel()
{
	return hungerlevel;
}

void Pet::setHungerLevel(int hunger)
{
	hungerlevel = hunger;
}

int Pet::getBoredomLevel()
{
	return boredomlevel;
}
void Pet::setBoredomLevel(int boredom)
{
	boredomlevel = boredom;
}

string Pet::getName()
{
	return name;
}
void Pet::setName(string name)
{
	Pet::name = name;
}

/*********************** lets begin ******************************************/

Pet::Pet(string name, int hunger, int boredom)
{
	setName(name);
	setHungerLevel(hunger);
	setBoredomLevel(boredom);
}

void Pet::Talk()
{
	if (PetMood() < 7)
		cout << getName() << " is feeling happy!" << endl;
	else if (PetMood() >= 7 && PetMood() < 16)
		cout << getName() << " is feeling okay." << endl;
	else if (PetMood() >=16 && PetMood() < 21)
		cout << getName() << " is feeling fustrated." << endl;
	else
		cout << getName() << " is feeling mad!" << endl;
	PassTime();
	DisplayPetBehavior();
}

void Pet::FeedPet(int in)
{
	if (in > 4)
		in = 4;
	if (in <= 0)
		in = 1;

	if (getHungerLevel() < in)
		setHungerLevel(getHungerLevel()-getHungerLevel());
	else
		setHungerLevel(getHungerLevel()-in);

	cout << getName() << " has been fed " << in << " pellets of food" << endl;
	PassTime();
	DisplayPetBehavior();
}

void Pet::Play(int in)
{
	if (in > 4)
		in = 4;
	if (in <= 0)
		in = 1;
	if (getBoredomLevel() < in)
		setBoredomLevel(getBoredomLevel()-getBoredomLevel());
	else
		setBoredomLevel(getBoredomLevel()-in);
	cout << getName() << " had " << in << " hours of fun." << endl;
	PassTime();
	DisplayPetBehavior();
}

void Pet::DisplayPetBehavior()
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

int Pet::PetMood()
{
	return getBoredomLevel() + getHungerLevel();
}

void Pet::PassTime(int time)
{
	setHungerLevel(getHungerLevel()+time);
	setBoredomLevel(getBoredomLevel()+time);
}

void Pet::menu()
{
	enum { TALK = 1, FEED, PLAY, QUIT };
	bool breakout = false;
	while (!breakout)
	{
		cout << "Pet: " << getName() << endl;
		cout << TALK << ". Talk with your pet." << endl;
		cout << FEED << ". Feed your pet." << endl;
		cout << PLAY << ". Play with your pet." << endl;
		cout << QUIT << ". Quit your pet." << endl;
		cout << "What would you like to do?" << endl << ":";
		int menuSelection = getch() - '0';
		//cls();
		system("cls");
		switch (menuSelection)
		{
		case TALK:
			Talk();
			break;
		case FEED:
			FeedPet((((rand()%509)*(rand()%349))%4));
			break;
		case PLAY:
			Play((((rand()%509)*(rand()%349))%4));
			break;
		case QUIT:
			breakout = true;
		default:
			break;
		}
	}
}
