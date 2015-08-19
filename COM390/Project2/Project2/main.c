/******************************************************************************
 *  Program: COM 390 - Project 2
 *   Author: Amrit Panesar <apanesar-77260@student.coleman.edu
 *     Date: 2015-08-11
 *  Purpose: Count from 0 to 100 and 100 to 0 two different ways.
 *****************************************************************************/

#include "main.h"

int i, j, k = 0, linebr = 80/3;
#define BUFARR 100
#define BUFLEN 3
int bufnum1[BUFARR], bufnum2[BUFARR], bufnum3[BUFARR];

int main(int argc, char** argv) {

	printf("%s\n", "Calculating...");

	if (hundred2zero() !=  TRUE) {
		printf("Error condition found, exiting early");
		return 1;
	}

	if (zero2hundred1() != TRUE) {
		printf("Error condition found, exiting early");
		return 1;
	}

	if (zero2hundred2() != TRUE) {
		printf("Error condition found, exiting early");
		return 1;
	}

	pause();

	printf("%s\n", "Printing Hundred to Zero..");
	for (i = 0; i < BUFARR; i++) {
		if (i % 10 == 0) {
			printf("\n");
		}
		printf("%03d ", bufnum1[i]);
	}
	printf("\n");
	pause();

	printf("%s\n", "Printing Hundred to Zero (1)");
	for (i = 0; i < BUFARR; i++) {
		if (i % 10 == 0) {
			printf("\n");
		}
		printf("%03d ", bufnum2[i]);
	}
	printf("\n");
	pause();

	printf("%s\n", "Printing Hundred to Zero (2)");
	for (i = 0; i < BUFARR; i++) {
		if (i % 10 == 0) {
			printf("\n");
		}
		printf("%03d ", bufnum3[i]);
	}
	printf("\n");
	pause();

	return 0;
}

bool hundred2zero() {
	for (i = 0; i < BUFARR; i++) {
		bufnum1[i] = i + 1;
	}
	return TRUE;
}

bool zero2hundred1() {
	j = BUFARR + 1;

	while (j > 0) {
		bufnum2[BUFARR - j] = --j;
	}

	return TRUE;
}

bool zero2hundred2() {
	k = BUFARR + 1;

zerohundred_loop:

	bufnum3[BUFARR - k] = --k;

	if (k >= 0) {
		goto zerohundred_loop;
	} else {
		goto zerohundred_done;
	}

zerohundred_done:

	return TRUE;
}

void pause() {
	printf("\n%s\n", "Press any key to continue. . .");
	getch();
}