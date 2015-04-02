#ifndef HOUSE_H
#define HOUSE_H
#include "Blackjack.h"

class House : public GenericPlayer
{
private:
public:
	House(const string &name = "Dealer");
	virtual ~House();

	virtual bool isHitting();
	void firstFirstCard();
};

#endif