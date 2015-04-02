#include <iostream>
#include <string>

using namespace std;

class Player
{
	int score;
	float health;
	string name;

public:
	Player();
	void setScore(int iScore);
	int getScore();

	void setHealth(float fHealth);
	float getHealth();

	void setName(string sName);
	string getName();

	void display();
	void run();
};