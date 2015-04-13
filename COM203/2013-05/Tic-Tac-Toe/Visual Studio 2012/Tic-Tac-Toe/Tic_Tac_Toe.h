#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class Tic_Tac_Toe {
private:
	bool isWin;
	char human;
	char computer;
	char board[9];
	int position;
	int easyMoves[9];
	bool instructionsdisplayed;

public:
	Tic_Tac_Toe();

	bool winner();
	bool stalemate();

	void displayInstructions();
	void run();
	void displayBoard();
	void isTie();

	void think(bool mode);
	void getInput();
	void initeasymoves();
	void initboard();
	
	void setisWin(bool isWin);
	bool getisWin();

	void sethuman(char human);
	char gethuman();

	void setcomputer(char computer);
	char getcomputer();

	void setboard(char* board);
	char* getboard();

	void setposition(int position);
	int getposition();

	void seteasyMoves(char* moves);
	char* geteasyMoves();
};

#endif