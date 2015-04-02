#ifndef PLAYER_H
#define PLAYER_H
#include "Blackjack.h"

class Player : public GenericPlayer
{
private:
public:
	Player(const string &name = "");
	virtual ~Player();

	virtual bool isHitting();
	bool win();
	bool loose();
	bool push();
};

#endif