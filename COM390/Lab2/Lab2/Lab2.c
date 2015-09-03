// Lab2.cpp : Defines the entry point for the console application.
//

#include "Lab2.h"

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <conio.h>
#include <malloc.h>

my_basic_structure_1 *pArray[LGBUFSIZE];
my_basic_structure_1 *pArray2[REGBUFSIZE];
my_basic_structure_1 *mbsPtr;
my_basic_structure_1 *mbsPtr2;

int i, j, k = 0;

void init() {
	for (i = 0; i < LGBUFSIZE; i++) {
		pArray[i] = (my_basic_structure_1*)malloc(sizeof(my_basic_structure_1));
		memset(pArray[i], '\0', sizeof(my_basic_structure_1));
	}
	mbsPtr = (my_basic_structure_1*) malloc(sizeof(my_basic_structure_1) * REGBUFSIZE);
	mbsPtr2 = mbsPtr;
	for (i = 0; i < REGBUFSIZE; i++) {
		memset(mbsPtr2, '\0', sizeof(my_basic_structure_1));
		mbsPtr2++;
	}
}

int main(int argc, char **argv)
{
	init();
	
	pause();

	cleanup();
	return 0;
}

void cleanup() {
	for (i = 0; i < LGBUFSIZE; i++) {
		free(pArray[i]);
	}
}

void pause() {
	printf("\n%s\n", "Press any key to continue. . . ");
	getch();
}