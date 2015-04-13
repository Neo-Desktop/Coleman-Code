/***************************************************************
 * Project: COM 203 Midterm
 *  Author: Amrit Panesar
 *    Date: 09/04/2014
 **************************************************************/

#pragma once

#include "includes.h"

// not a whole lot going on here
// just enough to be called from the account class

void ChangeConsoleTitle (const char* input);
void ChangeConsoleIcon (int resource_number);
void ConsoleSetup (char* input);
int GetYear();

void pause();
void cls();
void randSeed();
string spacePad(int input, int length = 7, bool right = false); // ah thank god for default arguments

enum { NUL = 0, SOH, STX, ETX, EOT, ENQ, ACK, BEL, BS, HT,
	   LF, VT, FF, CR, SO, SI, DLE, DC1, DC2, DC3, DC4, NAK, 
	   SYN, ETB, CAN, EM, SUB, ESC, FS, GS, RS, US, DEL = 127 };