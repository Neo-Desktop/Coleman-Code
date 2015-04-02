#include "Player.h"

int main()
{
	Player player;
	player.setHealth(9999);
	player.setScore(9001);

	cout << "Player has " << player.getHealth() << " health and a score of " << player.getScore() << endl;
	cin.get();
}