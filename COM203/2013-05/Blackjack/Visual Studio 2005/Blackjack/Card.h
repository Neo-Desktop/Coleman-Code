#ifndef CARD_H
#define CARD_H

#include "Blackjack.h"

class Card
{
private:
	bool isFaceUp;
public:
	enum RANK { ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum SUIT {	CLUBS, DIAMONDS, HEARTS, SPADES };

	Card(RANK rank = ACE, SUIT suit = SPADES, bool isFaceUp = true);

	int getValue();
	void flip();
protected:
	RANK rank;
	SUIT suit;
};

#endif