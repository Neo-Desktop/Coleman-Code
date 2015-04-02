#ifndef GAME_H
#define GAME_H

#include "Blackjack.h"

class Game
{
private:
	Deck deck;
	House house;
	Player player;
	
public:
	Game(const string &name);
	~Game();

	bool play();
};

#endif