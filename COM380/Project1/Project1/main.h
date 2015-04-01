#ifdef _WIN32
	#ifndef VC_EXTRALEAN
		#define VC_EXTRALEAN
		// no clue what this does, but lets be EXTRALEAN
	#endif // !VC_EXTRALEAN

	#ifndef WIN32_LEAN_AND_MEAN 
		// look how lean and mean we are!
		#define WIN32_LEAN_AND_MEAN 
	#endif // !WIN32_LEAN_AND_MEAN 

	#include <Windows.h>
#elif __linux__
	#include <unistd.h>
	#include <term.h>
#endif

#ifndef _main_h
	#define _main_h
	/* just your run of the mill header file */

	#include <iostream>
	#include <string>
	#include <sstream>
	#include <conio.h>

	#include <vector>
	#include "Tower.h"

	void pause();
	void sleep(int in);
	void creepyLoop(string in);
	void println(vector<Tower> &tvecs);
	void ClearScreen();
	int getInput(string prompt);

	int movePieces(vector<Tower> &tvecs, int currentStack, int from, int to, int helper, int moveaccumulator);

	string centerLine(string in);
	string centerLine(int len);

#endif // !_main_h
