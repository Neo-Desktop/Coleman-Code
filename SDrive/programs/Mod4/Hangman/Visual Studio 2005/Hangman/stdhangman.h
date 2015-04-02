#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <ctype.h>

#include <Windows.h>
#include <conio.h>

#include "Hangman.h"
#include "hangword.h"

using namespace std;

void pause();
void cursorpos(int x, int y);
void centerline(string input, int linenum);
void writeline(string input);
void writeline(int num);
void drawseperator();
void doseed();
void cls();
