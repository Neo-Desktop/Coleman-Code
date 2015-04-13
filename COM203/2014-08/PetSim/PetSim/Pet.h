
/******************************************************************************
 *   Pet.h - Define a pet object                                              *
 *  Author: Amrit Panesar <apanesar@coleman.edu>                              *
 *    Date: 08/18/2014                                                        *
 * License: Released into public domain                                       *
 *****************************************************************************/

#include "stdhead.h"

class Pet
{
private:
	int hungerlevel;
	int boredomlevel;
	string name;

	int PetMood();
	void PassTime(int time = 1);

	int getHungerLevel();
	void setHungerLevel(int hunger);

	int getBoredomLevel();
	void setBoredomLevel(int boredom);

	string getName();
	void setName(string name);
	

public:
	Pet(string name, int hunger = 0, int boredom = 0);
	void Talk();
	void FeedPet(int in);
	void Play(int in);
	void DisplayPetBehavior();
	void menu();

};