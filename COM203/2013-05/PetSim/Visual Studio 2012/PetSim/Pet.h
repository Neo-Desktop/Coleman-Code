/*****************************************************************************
 *   Author: Amrit Panesar                                       ,o/ ASP     *
 *     Date: 06-19-2013                                                      *
 *  Program: PetSimulator                                                    *
 *     File: pet.h                                                           *
 * Function: Holds the member variables and protypes for the Pet class.      *
 * Abstract: This file contains all necessary function prototypes and member *
 *           variables related to the Pet class as defined below. Includes   *
 *           iostream for user input and output, string for string usage,    *
 *           and ctime for seeding the random function used in Pet.cpp       *
 * Liscence: Released as Public Domain material.                             *
 ****************************************************************************/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Pet
{
private:
	string name;
	int hungerLevel;
	int boredomLevel;

	int petMood();
	void passTime(int time = 1);

public:
	Pet (string name, int hunger = 0, int boredom = 0);
	void setName(string in);
	string getName();

	void setHungerLevel(int in);
	int getHungerLevel();

	void setBoredomLevel(int in);
	int getBoredomLevel();

	void run();
	void menu();
	void talk();
	void play(int play = 1);
	void feedPet(int food = 1);
	void displayPetBehavior();

	void killedPet();
	void cls();
};