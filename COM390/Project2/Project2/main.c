/******************************************************************************
 *  Program: COM 390 - Project 2
 *   Author: Amrit Panesar <apanesar-77260@student.coleman.edu
 *     Date: 2015-08-11
 *  Purpose: Count from 100 to 0 and 0 to 100 two different ways.
 *****************************************************************************/

#include "main.h"

int i, j, k = 0;
char bufnum[3];

int main(int argc, char** argv) {

	if (hundred2zero() !=  TRUE) {
		printf("Error condition found, exiting early");
		return 1;
	}

	if (zero2hundred() != TRUE) {
		printf("Error condition found, exiting early");
		return 1;
	}

	pause();

	return 0;
}

bool hundred2zero() {
	for (i = 1; i <= 100; i++) {
		sprintf("%d03", i);
	}
	return TRUE;
}

bool zero2hundred() {
	j = 100;

	while (j > 0) {
		sprintf("%d03", j);
	}
	return TRUE;
}

void pause() {
	printf("Press any key to continue. . .");
	getch();
}