#ifndef HANGMAN_H
#define HANGMAN_H

#include "stdhangman.h"

class Hangman
{
private:
	int attempts;
	vector<hangword> wordList;
	vector<string> adminList;
	string secretWord;
	string revealedword;
	int wordLength;
	char alphabet[26];
	bool emessage;
	string message;
public:
	Hangman();
	bool playGame();
	void enterNewWords();
	bool isWin();
	void convertToUpper();
	void readFromFile();

	void setSecretWord(string word);
	string getSecretWord();

	void setWordLength(int length);
	int getWordLength();
	
	void initFile();
	bool notguessed(char guess);
	bool isinword(char guess);
	bool doadmin();
	void displayMenu();
	void drawhangman();
	bool handleinput();
	void blankguesses();
	void revealchar(char reveal);
	void chooseword();
	void drawletters();
};

#endif