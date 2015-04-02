#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H
#include "Blackjack.h"

class GenericPlayer : public Hand
{
private:
	string name;

public:
	GenericPlayer();
	virtual ~GenericPlayer();

	virtual bool isHitting();
	bool isBusted();
	bool bust();

	string getName();
	void setName(string name);
};

#endif