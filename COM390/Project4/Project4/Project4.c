// Project4.cpp : Defines the entry point for the console application.
//

#include "Project4.h"

#define holdsize 5

TtimeStruct holding[holdsize];

int i, j ,k = 0;

void init() {
	for (i = 0; i < holdsize; i++) {
		holding[i] = (TtimeStruct)malloc(sizeof(TravTimeStruct));
	}
}

void getInputs() {
	for (i = 0; i < holdsize; i++) {
		clrscr();
		printf("%s%d\n\n", "Input for #", i);
		printf("%s\n:", "Please enter a speed");
	}
}

int main(int argc, char **argv) {
	init();

	getInputs();

	pause();

	down();
	return 0;
}

void down() {
	for (i = 0; i < holdsize; i++) {
		free(holding[i]);
	}
}
