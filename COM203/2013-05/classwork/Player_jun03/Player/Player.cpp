#include <ctime>
#include "Player.h"

Player::Player()
{
	score = 0;
	health = 0;
	name = "";
}

void Player::setHealth(float fHealth)
{
	if (fHealth > 100)
		fHealth = 100;
	else if (fHealth < 0)
		fHealth = 0;

	health = fHealth;
}
float Player::getHealth()
{
	return health;
}

int Player::getScore()
{
	return score;
}
void Player::setScore(int iScore)
{
	score = iScore;
}

void Player::setName( string sName )
{
	name = sName;
}
string Player::getName()
{
	return name;
}

void Player::display()
{
	cout << "Player has " << getHealth() << " health and a score of " << getScore() << endl;
}

void Player::run()
{
	cout << "Would you like to play a game?\n:";
	char playG;
	cin >> playG;

	while (playG == 'y' || playG == 'Y')
	{
		int thisScore = 0;
		int cScore = 0;

		int wCount = 0;
		while (wCount < 5)
		{
			srand((unsigned int)time(NULL)+rand()%30+rand()%100);
			thisScore += rand() % 100 + 1;
			wCount++;
		}
		setScore(thisScore);

		cout << "Player 1: " << getName() << ", your score is: " << getScore() << endl;

		cout << "Would you like to play again?\n:";
		cin >> playG;
	}
}