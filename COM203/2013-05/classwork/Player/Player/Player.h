#include <iostream>
#include <string>

using namespace std;

class Player
{
	int score;
	float health;

public:
	void setScore(int iScore);
	int getScore();

	void setHealth(float fHealth);
	float getHealth();

	void display();
};