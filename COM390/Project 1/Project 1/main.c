/******************************************************************************
 *  Program: COM 390 - Project 1
 *   Author: Amrit Panesar <apanesar-77260@student.coleman.edu
 *     Date: 2015-08-11
 *  Purpose: Prompt the user for their name, display the fact that they enjoy
 *           programming in C, and state that it is indeed a piece of cake.
 *****************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <string.h>

const char* CAKE		= "               \xdc\n                \xdb\n            \xdc\xdc \xdc\xdf\n         \xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdc     \xdc\xdc\xdc\xdc\xdc\xdc\xdb\xdb\xdb\xdf\xdb\n       \xdc\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdf\xdf\xdf \xdc\xdc\xdb\xdf\xdb\xdc\xdb\xdb\xdb\n     \xdb\xdf\xdf\xdf \xdb\xdb\xdb\xdb\xdb\xdf\xdf\xdc\xdb\xdf\xdc\xdc\xdf\xdf\xdc\xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n     \xdb\xdf\xdc\xdc\xdc\xdc\xdb\xdb\xdb \xdc\xdc\xdb\xdf\xdf\xdc\xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\xdf\xdc\xdc\n     \xdb    \xdf\xdf\xdf\xdf\xdf\xdf\xdc\xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\xdf\xdc\xdc\xdb\xdb\xdb\xdb\n     \xdb         \xdb\xdb\xdb\xdb\xdb\xdf\xdf\xdf\xdc\xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\n     \xdb         \xdb\xdf\xdf \xdc\xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\xdb\xdc\xdc\xdb\n     \xdb         \xdc\xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\xdb\xdc\xdb\xdb\xdb\xdb\xdb\xdb\n     \xdb         \xdb\xdb\xdb\xdb\xdf\xdf\xdc\xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\xdf\n     \xdb         \xdf\xdf\xdc\xdc\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\xdf\n     \xdb         \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdf\xdf\n      \xdf\xdc\xdc\xdc     \xdb\xdb\xdb\xdf\xdf\n          \xdf\xdf\xdf\xdf\xdf\xdf";

const char* HELLO		="I love Programming in C\n";

const char* TOKENS		= " ";

const int	TOKENINDEX	= 1; // insert name after token 0

char name[256], out[256];
char *token, *nextToken = NULL;

int i = 0;


// lets begin

int main(int argc, char **argv) {

	printf("%s\n:", "Please enter your name"); // prompt for name
	gets_s(name, sizeof(name)); // set the string into the buffer
	printf("\n\n"); // new lines

	strcpy(out, HELLO); // copy the string to be tokenized into a mutable buffer

	token = strtok(out, TOKENS); // start the tokenizer
	
	for (i = 0; token != NULL; i++) // time to loop over the tokens
	{
		if (i == TOKENINDEX) {
			printf(", %s,", name); // insert after the token index
		}

		if (i == 0) {
			printf("%s", token); // token 0 does not get a space (anticipation for name/token 1)
		} else {
			printf(" %s", token); // display a space followed by the token data
		}
		
		token = strtok(NULL, TOKENS); // delta next token
	}

	printf("\n\n%s\n%s\n", "It's a piece of cake!", CAKE); // cake

	printf("\n%s\n", "Press any key to continue. . ."); 
	getch(); // pause

	return 0; // done!
}