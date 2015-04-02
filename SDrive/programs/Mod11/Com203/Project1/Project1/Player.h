#include <string>

using namespace std;

class Player {

private:
	int iScore;
	int iHealth;
	string sName;
public:
	Player(int score, int health, string name);
	void setScore(int score);
	int getScore();

	void setHealth(int health);
	int getHealth();

	string getName();
	void setName(string Name);

	void display();
};
