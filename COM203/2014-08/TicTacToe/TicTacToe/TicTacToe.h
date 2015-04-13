
#include "includes.h"

#pragma once
#define boardsize 9
class TicTacToe
{
private:
	string playername;
	bool isWin;
	bool instructionsdisplayed;
	char human;
	char computer;
	char board[boardsize];
	int position;

	/*
	0 | 1 | 2
	3 | 4 | 5
	6 | 7 | 8
	*/
	vector< vector<int> > wins;
	static int easyMoves[];

public:
	TicTacToe(string playername, char playerchar, char computerchar);
	void displayInstructions();
	void run();
	void displayBoard();
	bool winner();
	bool isTie();
	void getInput();
	void initboard();
	bool stalemate();
	void think(bool iseasy);

	void setplayername(string playername);
	string getplayername();

	void setiswin(bool isWin);
	bool getiswin();

	void sethuman(char human);
	char gethuman();

	void setcomputer(char computer);
	char getcomputer();

	void setboard(char* board);
	char* getboard();

	void setposition(int position);
	int getposition();
	void initwins();
};