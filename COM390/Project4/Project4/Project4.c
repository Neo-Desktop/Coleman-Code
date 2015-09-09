/******************************************************************************
 *  Author: Amrit Panesar
 * Project: 4 - Structs/Malloc
 *    Date: 09/08/2015
 * Purpose: Create a multidimensional array on the fly and populate its children
 *          Display the results.
 *****************************************************************************/

#include "Project4.h"

#define holdsize 10

TtimeStruct* holding;

int i, j ,k = 0;


void init() {
	srand(time(NULL));

	holding = (TtimeStruct*)malloc(sizeof(TtimeStruct) * holdsize);

	for (i = 0; i < holdsize; i++) {
		holding[i] = (TtimeStruct)malloc(sizeof(TravTimeStruct));
	}
}

void getInputs() {
	for (i = 0; i < holdsize; i++) {
		holding[i]->currentTimestamp = time(NULL);
		holding[i]->distance = rand()%100;
		holding[i]->speed = rand()%100;
	}
}

void printStructs() {
	for (i = 0; i < holdsize; i++) {
		printf("%s%d\n", "Structure #", i);
		printf("%s%d\n", "Time: ", holding[i]->currentTimestamp);
		printf("%s%d\n", "Distance: ", holding[i]->distance);
		printf("%s%d\n", "Speed: ", holding[i]->speed);
		printf("%s\n\n", "-----------------------");
	}
}

int main(int argc, char **argv) {
	init();

	getInputs();
	printStructs();

	down();

	pause();
	return 0;
}

void down() {
	for (i = 0; i < holdsize; i++) {
		free(holding[i]);
	}
	free(holding);
}
