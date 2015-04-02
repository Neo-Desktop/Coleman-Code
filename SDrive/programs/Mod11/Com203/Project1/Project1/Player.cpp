#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

Player::Player(int score, int health, string name)
{
	setScore(score);
	setHealth(health);
	setName(name);
}

void Player::setScore(int score)
{
	if ( score <= 0 )
	{
		score = 0;
	}
	iScore = score;
}

int Player::getScore()
{
	if ( iScore <= 0 )
	{
		iScore = 0;
	}
	return iScore;
}

void Player::setHealth(int health)
{
	if ( health >= 0 && health <= 100 )
	{
		iHealth = health;
	}
}

int Player::getHealth()
{
	if ( iHealth <= 0 )
	{
		iHealth = 0;
	}
	if ( iHealth >= 100 )
	{
		iHealth = 100;
	}
	return iHealth;
}

void Player::setName(string name)
{
	sName = name;
}

string Player::getName()
{
	return sName;
}

void Player::display()
{
	cout << "\tScore: " << getScore() << endl;
	cout << "\tHealth: " << getHealth() << endl;
}