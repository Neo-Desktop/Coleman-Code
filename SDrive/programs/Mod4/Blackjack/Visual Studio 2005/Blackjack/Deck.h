#ifndef DECK_H
#define DECK_H

#include "Blackjack.h"

class Deck : public Hand
{
private:
public:
	Deck();
	virtual ~Deck();
	void populate();
	void shuffle();
	void deal();
	void additionalCards(GenericPlayer &aGenericPlayer);
};

#endif